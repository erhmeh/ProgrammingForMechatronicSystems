#include "DataFusion.h"

// Constructor initialies the class object //////////////////////////////////////////////////////////////////////////
DataFusion::DataFusion(){
    _fusionMethod = DEFAULT_FUSION_METHOD;
    _DataProcessedTime = INITIAL_DATA_PROCESSED_TIME; // 0.0 for the start of the fusion process
}

// Ranger Fusion (CLASS) Setters ////////////////////////////////////////////////////////////////////////////////////

void DataFusion::setFusionMethod(std::string fusionMethod){
    _fusionMethod = fusionMethod;
}

// Ranger Fusion (CLASS) Getters ////////////////////////////////////////////////////////////////////////////////////

std::string DataFusion::getFusionMethod(){
    return _fusionMethod;
}

// Data Fusion Source file Function - Print deque Function //////////////////////////////////////////////////////////
void printDeque(std::deque<double> dataDeque){
    std::deque<double> data;
    for (int i = 0; i < dataDeque.size() ; i++){
        data.push_back(dataDeque[i]);
    }
    while (!data.empty()){
        double printedData = data.front();
        data.pop_front();
        std::cout << printedData;
        if(!data.empty()){
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Data Fusion Source file Function - Ranger Fusion Thread //////////////////////////////////////////////////////////
void DataFusion::rangerFusionThread(std::deque<std::deque<double> >& rawData
                                    ,std::deque<std::deque<double> >& sonarDataBuffer
                                    ,std::deque<std::deque<double> >& radarDataBuffer
                                    ){
    while (true){
        std::unique_lock<std::mutex> locker(_mutex);
        if (!rawData[rangerDeque].empty() || !rawData[timeDeque].empty() || !rawData[maxDeque].empty()){
            // Start Data Output //
            std::cout << "------------------------------------------------------" << std::endl;
            std::cout << "TimeStamp: " << (std::chrono::duration_cast<std::chrono::microseconds>
                                           (std::chrono::system_clock::now().time_since_epoch()).count()
                                           - _startTime) << std::endl;

            std::cout << "SonarBuffer: ";
            printDeque(sonarDataBuffer[rangerDeque]);

            std::cout << "RadarBuffer: ";
            printDeque(radarDataBuffer[rangerDeque]);

            // Removes the (-1) placeholder for printing new data //
            bool frontPopped = false;
            if (rawData[rangerDeque].front() == (-1)){
                rawData[rangerDeque].pop_front();
                frontPopped = true;

            }
            std::cout << "New Data: ";
            printDeque(rawData[rangerDeque]);

            // Adds the (-1) placeholder that was removed after printing new data //
            if (frontPopped == true){
                rawData[rangerDeque].push_front(-1);
            }

            std::deque<std::deque<std::deque<double> > > rawDataDeque;
            rawDataDeque = {sonarDataBuffer, radarDataBuffer};
            // Adds the time of interupt and a ranger of -1 to the rawDataDeque
            if (rawData[rangerDeque].front() == -1){
                rawDataDeque.push_back({{rawData[rangerDeque].front()},{rawData[timeDeque].front()}, {rawData[maxDeque].front()}});
            }

            std::deque<std::deque<double> > fusedData = rangerFusion(rawDataDeque);

            // Start Fused Data Output //
            for (int i = 0 ; i < _dataUsedForFusion.size() ; i++){
                std::cout << "Data To Be Fused: ";
                printDeque(_dataUsedForFusion[i]);
            }
            std::cout << "Fused Data: ";
            printDeque(fusedData[rangerDeque]);
            fusedData[rangerDeque].clear();

            fusedData[timeDeque].clear();
            // End Fused Data Output //

            // clear the notifyFlag and confirm that the interupt has been received and processed //
            if (rawData[rangerDeque].front() == -1){
                _5HzNotifyFlag = false;
            }

            rawData[rangerDeque].clear();
            rawData[timeDeque].clear();
            rawData[maxDeque].clear();

        }else{
            // wait untill data is ready to be consumed
            _condvar.wait(locker);
        }
    }
}

// Data Fusion Source file Function - Notify Thread /////////////////////////////////////////////////////////////////
void DataFusion::notifyThread(std::deque<std::deque<double> >& rawData){
    _startTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    _5HzNotifyFlag = false;
    int counter = 0;
    while (true){
        if (_5HzNotifyFlag == false){
            int timeElapsed = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - _startTime;
            if ((timeElapsed/200000) > counter){
                counter++;
                std::unique_lock<std::mutex> rangerlocker(_mutex);
                _5HzNotifyFlag = true;
                rawData[rangerDeque].push_back(-1); // Place Holder in list to be Processed //
                rawData[timeDeque].push_back(timeElapsed); // Time to be seached for when being processed //
                rawData[maxDeque].push_back(0); // not maxed out
                _mutex.unlock();
            }
        }else if(_5HzNotifyFlag == true){
            _condvar.notify_all();
        }
    }
}

// Data Fusion Source file Function - Ranger Fusion /////////////////////////////////////////////////////////////////
std::deque<std::deque<double> > DataFusion::rangerFusion(std::deque<std::deque<std::deque<double> > > rawDataDeque){

    _returnDeque = {{},{}};
    _rawDataUnprocessed = {{{},{},{}},{{},{},{}},{{},{},{}}};

    for(int i = 0 ; i < rawDataDeque.size() ; i++){
        for (int j = 0 ; j < rawDataDeque[i][rangerDeque].size() ; j++){
            if (rawDataDeque[i][timeDeque][j] > _DataProcessedTime){
                _DataProcessedTime = rawDataDeque[i][timeDeque][j];
                _rawDataUnprocessed[i][rangerDeque].push_back(rawDataDeque[i][rangerDeque][j]);
                _rawDataUnprocessed[i][timeDeque].push_back(rawDataDeque[i][timeDeque][j]);
                _rawDataUnprocessed[i][maxDeque].push_back(rawDataDeque[i][maxDeque][j]);
            }
        }
    }

    // Initialised the Data Used For Fusion Deque for the output //
    _dataUsedForFusion = {};

    while (true){
        //tests if the sensor Deques of the Deque _rawDataUnprocessed have any data in them, if no data exists program breaks out of the loop
        int breakCondition = 0;
        for(int i = 0 ; i < rawDataDeque.size() ; i++){
            if(_rawDataUnprocessed[i][rangerDeque].empty() && _rawDataUnprocessed[i][timeDeque].empty() && _rawDataUnprocessed[i][maxDeque].empty()){
                ++breakCondition;
            }
        }
        if(breakCondition == rawDataDeque.size()){
            break;
        }

        _dataToBeFused = {{},{}};
        _extrapolationData = {{},{}};


        //find the sensor with the earliest data value recorded

        std::deque<std::deque<double> > compareLatestDataTimes = {{},{}};

        for(int i = 0 ; i < rawDataDeque.size() ; i++){
            if (!_rawDataUnprocessed[i][rangerDeque].empty() && !_rawDataUnprocessed[i][timeDeque].empty() && !_rawDataUnprocessed[i][maxDeque].empty()){
                compareLatestDataTimes[0].push_back(i); // sensor number
                compareLatestDataTimes[1].push_back(_rawDataUnprocessed[i][timeDeque].front()); // data time
            }
        }

        double nextTime = compareLatestDataTimes[1][0];
        _latestDataSensor = compareLatestDataTimes[0][0];
        for (int i = 1 ; i < compareLatestDataTimes[0].size() ; i++){
            if (compareLatestDataTimes[1][i] < nextTime){
                nextTime = compareLatestDataTimes[1][i];
                _latestDataSensor = compareLatestDataTimes[0][i];
            }
        }

        dataManipulation(rawDataDeque);

        _returnDeque[rangerDeque].push_back(fusionProcess());
    }
    return _returnDeque;
}

// Data Fusion Source file Function - Fusion Process ////////////////////////////////////////////////////////////////
double DataFusion::fusionProcess(){

//     tests if sonar is at its max reading and if all radars are greater than the max sonar then disregards the sonar readings
//     x is a vector that contains all of the data values that need to be fused.
    double minValue = _dataToBeFused[data][0]; // starting point
    for (int i = 1 ; i < _dataToBeFused[data].size() ; i++){
        if (_dataToBeFused[data][i] < minValue){
            minValue = _dataToBeFused[data][i];
        }
    }
    std::deque<double> newDataToBeFused = {};
    bool removeValue = false;
    for (int i = 0 ; i < _dataToBeFused[max].size() ; i++){
        if (_dataToBeFused[max][i] == 1 && _dataToBeFused[data][i] == minValue){
            for (int j = 0 ; j < _dataToBeFused[max].size() ; j++){
                if (_dataToBeFused[max][j] == 0 && _dataToBeFused[data][j] > minValue){
                    removeValue = true;
                }
            }
        }
        if (removeValue == false){
            newDataToBeFused.push_back(_dataToBeFused[data][i]);
        }else if (removeValue == true){
            removeValue = false;
        }
    }

    _dataUsedForFusion.push_back(newDataToBeFused);

    // Calculates the Min from the values passed to this function in the vector //
    if (_fusionMethod == "Min"){
        double min = newDataToBeFused[0]; //min becomes first value in the vector
        for (int i = 1 ; i < newDataToBeFused.size() ; i++){ // iterate from second value
            if (newDataToBeFused[i] < min){
                min = newDataToBeFused[i];
            }
        }
        return min;
    }
    // Calculates the Average from the values passed to this function in the vector //
    else if (_fusionMethod == "Average"){
        double average;
        for (int i = 0 ; i < newDataToBeFused.size() ; i++){
            average = (newDataToBeFused[i] + (average*(i)))/(i+1);
        }
        return average;
    }
    // Calculates the Max from the values passed to this function in the vector //
    else if (_fusionMethod == "Max"){
        double max;
        for (int i = 0 ; i < newDataToBeFused.size() ; i++){
            if (newDataToBeFused[i] > max){
                max = newDataToBeFused[i];
            }
        }
        return max;
    }
}

// Data Fusion Source file Function - Data Manipulation /////////////////////////////////////////////////////////////
void DataFusion::dataManipulation(std::deque<std::deque<std::deque<double> > > rawDataDeque){
    // Take the latest sensor reading time and extrapolate all other sensors for this point in time //

    // Pass the latest data to the data to be fused vector //
    _dataToBeFused[data].push_back(_rawDataUnprocessed[_latestDataSensor][rangerDeque].front());
    _dataToBeFused[max].push_back(_rawDataUnprocessed[_latestDataSensor][maxDeque].front());

    // push the time that data was created to the returnDeque as this will be the same for every case //
    _returnDeque[timeDeque].push_back(_rawDataUnprocessed[_latestDataSensor][timeDeque].front());

    int latestDataSensor = _latestDataSensor;

    // If it the ranger data is equal to (-1) this means that the 5Hz interupt was triggered //
    if (_rawDataUnprocessed[_latestDataSensor][rangerDeque].front() == -1){

        // make equal to (-1) so that it extrapolates all of the sensors //
        // i.e. there is no sensor in position -1 of the deque //
        latestDataSensor = -1;

        // remove the (-1) from the Data to be Fused
        _dataToBeFused = {{},{}};

    }

    // Pop the front of the Deque so that the next reading (if there is a next reading) can be processed //
    _rawDataUnprocessed[_latestDataSensor][rangerDeque].pop_front();
    _rawDataUnprocessed[_latestDataSensor][timeDeque].pop_front();
    _rawDataUnprocessed[_latestDataSensor][maxDeque].pop_front();

    int removeOne = 0;
    for (int i = 0 ; i < rawDataDeque.size() ; i++){
        if (rawDataDeque[i][rangerDeque][0] == -1){
            // notify that this interupt exists due to the (-1), so that this doesn't count as another sensor
            removeOne = 1;
        }
    }

    // Iterate through the other sensors to extrapolate a value from each sensor //
    for (int earlierDataSensor = 0 ; earlierDataSensor < (rawDataDeque.size()-removeOne) ; earlierDataSensor++){
        // Initialising the Deque used to store the two data points that will be used for the Extrapolation //
        _extrapolationData = {{},{}, {}};

        // If earlier Data Sensor is NOT equal to latest Data Sensor perform the Extrapolation //
        if (earlierDataSensor != _latestDataSensor){

            for (int i = (rawDataDeque[earlierDataSensor][timeDeque].size()-1) ; i >= 0 ; i--){
                if(_extrapolationData[rangerDeque].size() < 2){
                    if (rawDataDeque[earlierDataSensor][timeDeque][i] == _returnDeque[timeDeque].front()){
                        _dataToBeFused[data].push_back(rawDataDeque[earlierDataSensor][rangerDeque][i]);
                        _dataToBeFused[max].push_back(rawDataDeque[earlierDataSensor][maxDeque][i]);
                    }else if (rawDataDeque[earlierDataSensor][timeDeque][i] < _returnDeque[timeDeque].front()){
                        _extrapolationData[rangerDeque].push_front(rawDataDeque[earlierDataSensor][rangerDeque][i]);
                        _extrapolationData[timeDeque].push_front(rawDataDeque[earlierDataSensor][timeDeque][i]);
                        _extrapolationData[maxDeque].push_front(rawDataDeque[earlierDataSensor][maxDeque][i]);
                    }else if (rawDataDeque[earlierDataSensor][timeDeque][i] > _returnDeque[timeDeque].front()){
                        //null
                    }
                }
            }
            // If extrapolation is required with two variables in the extrapolation Deque based on the conditions above //
            // i.e. Extrapolation of a linear line from 2 points //
            if(_extrapolationData[rangerDeque].size() == 2){
                // Data used to perform the Extrapolation //
                double t0 = _extrapolationData[timeDeque][0];
                double t1 = _extrapolationData[timeDeque][1];
                double ty = _returnDeque[timeDeque].back();
                double X0 = _extrapolationData[rangerDeque][0];
                double X1 = _extrapolationData[rangerDeque][1];
                // Below is the formular for Extrapolation
                double Xy = (X1 + ((ty - t1)/(t1 - t0))*(X1 - X0)); // Unknown variable found using Extrapolation //

                // Adds the Extraploated data to the Data to be Fused Vector //
                _dataToBeFused[data].push_back(Xy);

                // Max Sensor value Indicators //
                double m0 = _extrapolationData[maxDeque][0];
                double m1 = _extrapolationData[maxDeque][1];

                // If both of the data points are at the sensor's max reading notify that sensor is at max //
                if (m0 == 1 && m1 == 1){
                    _dataToBeFused[max].push_back(1);
                }

                // Else Notify that sensor is not at max //
                else{
                    _dataToBeFused[max].push_back(0);
                }
            }
            // If extrapolation is not required as there is only one variable to refer from at the start of the fusion process //
            // i.e. Extrapolation of a horizontal line from one point//
            else if(_extrapolationData[rangerDeque].size() == 1){
                _dataToBeFused[data].push_back(_extrapolationData[rangerDeque].front());
                _dataToBeFused[max].push_back(_extrapolationData[maxDeque].front());
            }
            // If there is no data but this function gets called - Print Error message //
            else if(_extrapolationData[rangerDeque].size() == 0){
                // ERROR //
                std::cout << "ERROR - NO VALUES TO BE EXTRAPOLATED" << std::endl;
            }
        }
    }
}
