#ifndef DATAFUSION
#define DATAFUSION

#include <string>
#include <vector>
#include <list>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

const std::string DEFAULT_FUSION_METHOD = "Average";
const double INITIAL_DATA_PROCESSED_TIME = 0.0;

/*!
 *  \ingroup   ac_shapre DataFusion
 *  \brief     DataFusion class
 *  \details
 *  This class fuses data from multiple sensors for an output of a range finder.\n
 *  \author    Jordan Henry
 *  \version   1.0
 *  \date      20/05/2018
 *  \pre       none
 *  \bug       none reported as of 20/05/2018
 *  \warning   none reported as of 20/05/2018
 */

class DataFusion {
public:
    // Constructor initialies the class object //
    DataFusion();

    // Ranger Fusion (CLASS) Setters //
    /**
     * @brief setFusionMethod : allows for the Fusion Method to be set
     * @param fusionMethod
     */
    void setFusionMethod(std::string fusionMethod);

    // Ranger Fusion (CLASS) Getters //
    /**
     * @brief getFusionMethod : returns the Fusion Method
     * @return
     */
    std::string getFusionMethod();

    // Ranger Fusion Thread //
    /**
     * @brief rangerFusionThread : Thread responsible for the data fusion
     * @param rawData
     * @param sonarDataBuffer
     * @param radarDataBuffer
     * @param sonarDataBufferTest
     * @param radarDataBufferTest
     */
    void rangerFusionThread(std::deque<std::deque<double> >& rawData
                            ,std::deque<std::deque<double> >& sonarDataBuffer
                            ,std::deque<std::deque<double> >& radarDataBuffer
//                            ,std::deque<std::deque<double> >& sonarDataBufferTest
//                            ,std::deque<std::deque<double> >& radarDataBufferTest
                            );

    // Notify Thread //
    /**
     * @brief notifyThread : Thread responsible to notify data fusion when to fuse data
     * @param rawData
     */
    void notifyThread(std::deque<std::deque<double> >& rawData);

    std::mutex _mutex;
    std::condition_variable _condvar;

private:

    // Ranger Fusion //
    /**
     * @brief rangerFusion : Method that controls the data fusion determining what time to extrapolate the data for
     * @param rawDataDeque
     * @return
     */
    std::deque<std::deque<double> > rangerFusion(std::deque<std::deque<std::deque<double> > > rawDataDeque);

    // Fusion Process //
    /**
     * @brief fusionProcess : Method that performs the fusion by selecting the min, max or average
     * , also sonar sensors are ignored if all of them has reached there max value and the radar
     * sensors are greater than the max sonar value
     * @return
     */
    double fusionProcess();

    // Data Manipulation //
    /**
     * @brief dataManipulation : Extrapolates the data to be fused
     * @param rawDataDeque
     */
    void dataManipulation(std::deque<std::deque<std::deque<double> > > rawDataDeque);

    // used to keep track of what is stored in each Deque used in the data Fusion
    enum dataToBeFused {data, max};
    dataToBeFused _dataToBeFusedType;

    // used to keep track of what is stroed in each of the Deques from the sensors
    enum dequeData {rangerDeque, timeDeque, maxDeque};
    dequeData _dequeDataType;

    double _startTime; // start time for the Data output at 5Hz.
    std::string _fusionMethod; //(Min/Max/Average)
    double _DataProcessedTime;
    bool _5HzNotifyFlag;
    int _latestDataSensor;

    // containers used to return and process the data
    std::deque<std::deque<double> > _returnDeque;
    std::deque<std::deque<std::deque<double> > > _rawDataUnprocessed;
    std::deque<std::deque<double> > _dataToBeFused;
    std::deque<std::deque<double> > _dataUsedForFusion;
    std::deque<std::deque<double> > _extrapolationData;
};

#endif // DATAFUSION
