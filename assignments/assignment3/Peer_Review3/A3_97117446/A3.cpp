#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cmath>
#include <vector>
#include <deque>

#include "Sonar.h"
#include "Radar.h"
#include "DataFusion.h"

enum dequeDataType { rangerDeque, timeDeque, MaxDeque };
dequeDataType DataType;

// Main Source file Function - Sensor Parameters ////////////////////////////////////////////////////////////////////

// Prints out the sensor parameter values

void sensorParameters(Ranger& Sensor)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Sensor: \t\t" << Sensor.getSensorName() << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Model: \t\t\t" << Sensor.getModel() << std::endl;
    std::cout << "Baud: \t\t\t" << Sensor.getBaud() << std::endl;
    std::cout << "Port: \t\t\t" << Sensor.getPort() << std::endl;
    std::cout << "Field of View: \t\t" << Sensor.getFieldOfView() << std::endl;
    std::cout << "Max Distance: \t\t" << Sensor.getMaxDistance() << " m" << std::endl;
    std::cout << "Min Distance: \t\t" << Sensor.getMinDistance() << " m" << std::endl;
    std::cout << "Data Rate: \t\t" << Sensor.getDataRate() << " Hz" << std::endl;
    std::cout << "Angular Resolution: \t" << Sensor.getAngularResolution() << " Degrees" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl << std::endl;
    std::cout << "------------------------------------------------------" << std::endl << std::endl;
}

// Main Source file Function - Clear Input //////////////////////////////////////////////////////////////////////////

// called when user inputing data to clear an insane input and ask for a new input

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid Input, Try again: - " << std::endl;
}

// Main Source file Function - Clear Input //////////////////////////////////////////////////////////////////////////

// called by changeParameter() function who specifies what parameter is needed to be
// changed waits for a user input value
// checks if the value is sane, if insane ask user for another input
// else assigns input to the parameter variable in the objects' class

void parameterInput(Ranger& Sensor, std::string parameter)
{
    std::vector <double> parameterOptions{0 };
    Sensor.getParameterOptions(parameter, parameterOptions);
    double input = 0;
    while (true)
    {
        std::cout << "New " << parameter << " (";
        for (int i = 0; i < parameterOptions.size(); i++)
        {
            if (parameterOptions[i] >= 0)
            {
                if (i > 0)
                {
                    std::cout << " or ";
                }
                std::cout << parameterOptions[i];
            }
            else
            {
                std::cout << "): ";
                break;
            }
        }
        std::cin >> input;
        std::cout << std::endl;
        bool valid = false;
        for (int i = 0; i < parameterOptions.size(); i++)
        {
            if (input == parameterOptions[i])
            {
                valid = true;
            }
        }
        if (input != -1 && (valid == true))
        {
            if (parameter == "Baud")
            {
                Sensor.setBaud(input);
            }
            else if (parameter == "Port")
            {
                Sensor.setPort(input);
            }
            else if (parameter == "Field Of View")
            {
                Sensor.setFieldOfView(input);
                parameter = "Angular Resolution";
            }
            if (parameter == "Angular Resolution")
            {
                Sensor.setAngularResolution(input);
            }
            break;
        }
        else
        {
            clearInput(); // clear insane input and lets the user know for user to try another input
            input = 0;
        }
    }
}

// Main Source file Function - Change Parameter /////////////////////////////////////////////////////////////////////

// Function is used by the queriesParameters() fuction to change the value of the
// parameter specified in queriesParameters()

void changeParameter(Ranger& Sensor, std::string Parameter)
{
    char input = 0;

    while (true)
    {
        std::cout << "Would you like to change the " << Parameter << "? (Y/N): ";
        std::cin >> input;
        std::cout << std::endl;
        if (input == 'Y' || input == 'y')
        {
            parameterInput(Sensor, Parameter);
            break;
        }
        else if (input == 'N' || input == 'n')
        {
            break;
        }
        else
        {
            clearInput(); // clear insane input and lets the user know for user to try another input
            input = 0;
        }
    }
}

// Main Source file Function - Queries Parameter ////////////////////////////////////////////////////////////////////

// Function Queries the configurable parameters of each of the sensors
// Prints out the sensor parameter values
// Asks the user if they would like to change any of the values
// calls changeParameter() fuction for the sensor parameters that the user would like to change
// Asks the user if the new parameters for the sensor are correct, else repeat calling changeParameters()

void queriesParameters(Ranger& Sensor)
{
    sensorParameters(Sensor);
    char input1 = 0;
    while (true)
    {
        std::cout << "Would you like to change the Baud, Port";
        if (Sensor.getModel() == "RAD-001")
        {
            std::cout << " or Field Of View";
        }
        std::cout << "? (Y/N): ";
        std::cin >> input1;
        std::cout << std::endl;
        if (input1 == 'Y' || input1 == 'y')
        {
            char input2 = 'N';
            while (true)
            {
                if (input2 == 'Y' || input2 == 'y')
                {
                    break;
                }
                else if (input2 == 'N' || input2 == 'n')
                {
                    changeParameter(Sensor, "Baud");
                    changeParameter(Sensor, "Port");
                    if (Sensor.getModel() == "RAD-001")
                    {
                        changeParameter(Sensor, "Field Of View");
                    }
                    sensorParameters(Sensor);
                }
                else
                {
                    clearInput(); // clear insane input and lets the user know for user to try another input
                }
                std::cout << "Are the parameters for (" << Sensor.getSensorName() << ") correct? (Y/N): ";
                std::cin >> input2;
                std::cout << std::endl;
            }
            break;
        }
        else if (input1 == 'N' || input1 == 'n')
        {
            break;
        }
        else
        {
            clearInput(); // clear insane input and lets the user know for user to try another input
        }
    }
}

// Main Source file Function - Queries Ranger Fusion Method /////////////////////////////////////////////////////////

// Function allows the user to change the ranger fusion method (min, average, max)
void queriesRangerFusionMethod(DataFusion& dataFusion)
{
    std::cout << "Ranger Fusion Method: " << dataFusion.getFusionMethod() << std::endl << std::endl;
    char userChangeFusionMethod;
    while (true)
    {
        std::cout << "Would you like to change the Ranger Fusion Method (Y/N): ";
        std::cin >> userChangeFusionMethod;
        std::cout << std::endl;
        if (userChangeFusionMethod == 'Y' || userChangeFusionMethod == 'y')
        {
            std::string userInputFusionMethod;
            while (true)
            {
                std::cout << "New Ranger Fusion Method (Min, Average, Max): ";
                std::cin >> userInputFusionMethod;
                if (userInputFusionMethod == "min"
                    || userInputFusionMethod == "MIN"
                    || userInputFusionMethod == "Min")
                {
                    userInputFusionMethod = "Min";
                }
                else if (userInputFusionMethod == "average"
                         || userInputFusionMethod == "AVERAGE"
                         || userInputFusionMethod == "Average")
                {
                    userInputFusionMethod = "Average";
                }
                else if (userInputFusionMethod == "max"
                         || userInputFusionMethod == "MAX"
                         || userInputFusionMethod == "Max")
                {
                    userInputFusionMethod = "Max";
                }
                if (userInputFusionMethod == "Min"
                    || userInputFusionMethod == "Average"
                    || userInputFusionMethod == "Max")
                {
                    dataFusion.setFusionMethod(userInputFusionMethod);
                    break;
                }
                else
                {
                    clearInput(); // clear insane input and lets the user know for user to try another input
                }
            }
            break;
        }
        else if (userChangeFusionMethod == 'N' || userChangeFusionMethod == 'n')
        {
            break;
        }
        else
        {
            clearInput(); // clear insane input and lets the user know for user to try another input
        }
    }
}

// Main Source file Function - General Sensor Thread of Type Ranger /////////////////////////////////////////////////
void sensorThread(Ranger& sensor, std::deque<std::deque<double> >& sensorData)
{
    sensor.sensorThread(sensorData);
}

// Main Source file Function - General Buffer Thread of Type Ranger /////////////////////////////////////////////////

// gains data from the sensors and then sends this data to to the fusion method.
void bufferThread(Ranger& sensor
                  , std::mutex& Mutex
                  , std::condition_variable& condvar
                  , std::deque<std::deque<double> >& sensorData
                  , std::deque<std::deque<double> >& rawData
                  , std::deque<std::deque<double> >& buffer
                  )
{
    sensor.bufferThread(Mutex, condvar, sensorData, rawData, buffer);
}

// Main Source file Function - General notify Thread ////////////////////////////////////////////////////////////////

// gains data from the sensors and then sends this data to to the fusion method.
void notifyThread(DataFusion& dataFusion, std::deque<std::deque<double> >& rawData)
{
    dataFusion.notifyThread(rawData);
}

// Main Source file Function - Ranger Fusion Thread /////////////////////////////////////////////////////////////////
void rangerFusionThread(std::deque<std::deque<double> >& rawData
                        , std::deque<std::deque<double> >& sonarDataBuffer
                        , std::deque<std::deque<double> >& radarDataBuffer
                        , DataFusion& dataFusion
                        )
{
    dataFusion.rangerFusionThread(rawData, sonarDataBuffer, radarDataBuffer);

}

// Main Thread //////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

    // Initialises the Data Fusion object to fuse the sensor data.
    DataFusion dataFusion;

    // Initialises the sensors (1 Sonar, 1 Radar)
    Sonar rangerSonar;
    Radar rangerRadar;

    rangerSonar.setSensorName("Sensor 1:- RangerSonar");
    rangerRadar.setSensorName("Sensor 2:- RangerRadar");

    // Queries the fixed sensor parameters for Sensors
    // Sets Sensor parameters as specified by the user
    queriesParameters(rangerSonar);
    queriesParameters(rangerRadar);

    // outputs a summary of the sensor parameters both configurable and NOT configurable.
    std::cout << "Summary of Sensors: " << std::endl << std::endl;
    sensorParameters(rangerSonar);
    sensorParameters(rangerRadar);

    queriesRangerFusionMethod(dataFusion);

    // try and remove this !!!! //
    std::deque<std::deque<double> > rawData = { {}, {}, {} };

    std::deque<std::deque<double> > sonarData = { {}, {}, {} };
    std::deque<std::deque<double> > radarData = { {}, {}, {} };
    std::deque<std::deque<double> > sonarDataTest = { {}, {}, {} };
    std::deque<std::deque<double> > radarDataTest = { {}, {}, {} };

    std::deque<std::deque<double> > sonarDataBuffer = { {}, {}, {} };
    std::deque<std::deque<double> > radarDataBuffer = { {}, {}, {} };
    std::deque<std::deque<double> > sonarDataBufferTest = { {}, {}, {} };
    std::deque<std::deque<double> > radarDataBufferTest = { {}, {}, {} };

    // Create the threads //
    std::thread Thread_rangerSonar(sensorThread
                                   , std::ref(rangerSonar)
                                   , std::ref(sonarData)
                                   );
    std::thread Thread_rangerRadar(sensorThread
                                   , std::ref(rangerRadar)
                                   , std::ref(radarData)
                                   );
    std::thread Thread_bufferSonar(bufferThread
                                   , std::ref(rangerSonar)
                                   , std::ref(dataFusion._mutex)
                                   , std::ref(dataFusion._condvar)
                                   , std::ref(sonarData)
                                   , std::ref(rawData)
                                   , std::ref(sonarDataBuffer)
                                   );
    std::thread Thread_bufferRadar(bufferThread
                                   , std::ref(rangerRadar)
                                   , std::ref(dataFusion._mutex)
                                   , std::ref(dataFusion._condvar)
                                   , std::ref(radarData)
                                   , std::ref(rawData)
                                   , std::ref(radarDataBuffer)
                                   );
    std::thread Thread_notify(notifyThread
                              , std::ref(dataFusion)
                              , std::ref(rawData)
                              );
    std::thread Thread_rangerFusion(rangerFusionThread
                                    , std::ref(rawData)
                                    , std::ref(sonarDataBuffer)
                                    , std::ref(radarDataBuffer)
                                    , std::ref(dataFusion)
                                    );

    Thread_rangerSonar.join();
    Thread_rangerRadar.join();
    Thread_bufferRadar.join();
    Thread_bufferSonar.join();
    Thread_notify.join();
    Thread_rangerFusion.join();

    return 0;
}
