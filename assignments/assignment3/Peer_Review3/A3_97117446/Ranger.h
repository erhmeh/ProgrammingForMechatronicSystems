#ifndef RANGER
#define RANGER

#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <deque>
#include <mutex>
#include <condition_variable>
#include "SensorDataGenerator.h"

/*!
 *  \ingroup   ac_shapre Ranger
 *  \brief     Ranger base class
 *  \details
 *  This class is the base class for all sensors used for a range finder.\n
 *  \author    Jordan Henry
 *  \version   1.0
 *  \date      20/05/2018
 *  \pre       none
 *  \bug       none reported as of 20/05/2018
 *  \warning   none reported as of 20/05/2018
 */

class Ranger {
public:
    // Constructor initialies the class object //
    Ranger();

    // Ranger(ABSTRACT BASE CLASS) Setters //

    /**
     * @brief setBaud : sets the sensors Baud
     * @param Baud
     */
    void setBaud(int Baud);

    /**
     * @brief setPort : sets the sensors Port
     * @param Port
     */
    void setPort(int Port);

    /**
     * @brief setFieldOfView : sets the sensors Field of View
     * @param fieldOfView
     */
    void setFieldOfView(double fieldOfView);

    /**
     * @brief setAngularResolution : sets the sensors Angular Resolution
     * @param Angular_Resolution
     */
    void setAngularResolution(double Angular_Resolution);

    /**
     * @brief setSensorName : sets the sensors Name
     * @param Sensor_Name
     */
    void setSensorName(std::string Sensor_Name);

    // Ranger(ABSTRACT BASE CLASS) Getters //

    /**
     * @brief getModel : gets the sensors model
     * @return
     */
    std::string getModel();

    /**
     * @brief getBaud : gets the sensors Baud
     * @return
     */
    int getBaud();

    /**
     * @brief getPort : gets the sensors Port
     * @return
     */
    int getPort();

    /**
     * @brief getFieldOfView : gets the sensors Field of View
     * @return
     */
    int getFieldOfView();

    /**
     * @brief getAngularResolution : gets the sensors Angular Resolution
     * @return
     */
    int getAngularResolution();

    /**
     * @brief getMaxDistance : gets the sensors Max Distance
     * @return
     */
    double getMaxDistance();

    /**
     * @brief getMinDistance : gets the sensors Min Distance
     * @return
     */
    double getMinDistance();

    /**
     * @brief getDataRate : gets the sensors Data Rate
     * @return
     */
    double getDataRate();

    /**
     * @brief getSensorName : gets the sensors Name
     * @return
     */
    std::string getSensorName();

    /**
     * @brief getParameterOptions : gets a vector of the possible values for a specific sensor parameter of which can be changed
     * @param parameter
     * @param options
     */
    void getParameterOptions(std::string parameter, std::vector<double>& options);

    /**
     * @brief getOrientationOffset : gets the sensors Orientation Offset
     * @return
     */
    double getOrientationOffset();

    /**
     * @brief getMaxOrientationOffset : gets the sensors Max Orientation Offset
     * @return
     */
    double getMaxOrientationOffset();

    /**
     * @brief getMinOrientationOffset : gets the sensors Min Orientation Offset
     * @return
     */
    double getMinOrientationOffset();

    /**
     * @brief getBufferDelay : gets the sensors Buffer Delay
     * @return
     */
    int getBufferDelay();

    /**
     * @brief getStartTime : gets the sensors start time
     * @return
     */
    double getStartTime();

    // Sensor Thread //
    /**
     * @brief sensorThread : method that contains the Sensor Thread that is responsible to produce data values at
     * the sensors data rate
     * @param sensordataBuffer
     */
    void sensorThread(std::deque<std::deque<double> >& sensordataBuffer);

    // Buffer Thread //
    /**
     * @brief bufferThread : method that contains the Buffer Thread that is resopnsible to buffer the data before it
     * is passed onto the data fusion
     * @param Mutex
     * @param condvar
     * @param sensorData
     * @param rawData
     * @param buffer
     */
    void bufferThread(std::mutex& Mutex
                      ,std::condition_variable& condvar
                      ,std::deque<std::deque<double> >& sensorData
                      ,std::deque<std::deque<double> >& rawData
                      ,std::deque<std::deque<double> >& buffer);

protected:

    // virtual destructor to make the Derived class abstract to ensure nobody tries and instantiate an object of type Ranger //
    virtual ~Ranger() = 0;

    std::string _model = "0"; // Sensor Model Number

    int _baud = 0; // Sensor Baud Rate
    int _defaultBaud = 0;
    std::vector<double> _baudOptions = {-1};

    int _port = 0; // Sensor USB Port Number
    int _defaultPort = 0;
    std::vector<double> _portOptions = {-1};

    double _fieldOfView = 0.0; // Sensor Field of View
    double _defaultFieldOfView = 0.0;
    std::vector<double> _fieldOfViewOptions = {-1};

    double _angularResolution = 0.0; // Sensor Angular resolution
    double _defaultAngluarResolution = 0.0;
    std::vector<double> _angularResolutionOptions = {-1};

    double _maxDistance = 0.0; // Sensor maximum reading

    double _minDistance = 0.0; // Sensor minimum reading

    double _dataRate = 0.0; // Rate that data is recorded by sensor

    double _orientationOffset = 0.0;
    double _maxOrientationOffset = 0.0;
    double _minOrientationOffset = 0.0;

private:

    // Valid //
    /**
     * @brief valid : Methods used to check if parameter input of type int is valid
     * @param option
     * @param input
     * @return
     */
    bool valid(std::vector<int> option, int input);

    // Valid //
    /**
     * @brief valid : Methods used to check if parameter input of type double is valid
     * @param option
     * @param input
     * @return
     */
    bool valid(std::vector<double> option, double input);

    // Data Generator //
    /**
     * @brief DataGenerator : Generates the sensor data
     */
    void DataGenerator();

    // Buffer Function //
    /**
     * @brief bufferFunct : makes a copy of producerBuffer and stores it in consumer Buffer
     * User defined bufferFlag settings
     * @param consumerBuffer
     * @param producerBuffer
     * @param bufferFlag
     */
    void bufferFunct(std::deque<std::deque<double> >& consumerBuffer
                     ,std::deque<std::deque<double> >& producerBuffer
                     ,bool bufferFlag);

    // Buffer Function //
    /**
     * @brief bufferFunct : makes a copy of producerBuffer and stores it in consumer Buffer
     * Default bufferFlag settings
     * @param consumerBuffer
     * @param producerBuffer
     */
    void bufferFunct(std::deque<std::deque<double> >& consumerBuffer
                     ,std::deque<std::deque<double> >& producerBuffer);

    enum dequeData {rangerDeque, timeDeque, maxDeque};
    dequeData _dequeDataType;

    std::mutex _sensorMutex;
    std::condition_variable _sensorcondvar;

    int _bufferDelay;
    bool _timeStarted;
    double _startTime;

    std::string _sensorName; // Name of the sensor used for output

    //Sensor Parameters used for the Fusion of data
    int _numberOfSamples = 0; // Number of samples in the _data vector
    std::vector<double> _data = {};
    SensorDataGenerator SensorData; // object of the Random Number generator
};


#endif // RANGER
