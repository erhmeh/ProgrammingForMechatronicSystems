//axis_accelerometer_sensor.h by Mitchell Galea (97115051) Date: 27/03/2018
#include <string>

#ifndef AXIS_ACCELEROMETER_SENSOR
#define AXIS_ACCELEROMETER_SENSOR

//fixed sampling time and resolution values defined as macros
#define FIXED_SAMPLING_TIME 10
#define FIXED_SAMPLING_RESOLUTION 1024
//default baud and max acceleration values defined as macros
#define DEFAULT_PORT "dev/ttyUSB0"
#define DEFAULT_BAUD  19200
#define DEFAULT_MAX_ACCELERATION  10



// Declaration of the axis accelerometer class
class axis_acc_sensor {

// Public members which are accessible from outside the class
public:

// Declaration of DEFAULT constructor, the default constructor
// will set all required variables to default values
// Default values are defined as macros
// Defaut values set to ensure sensor will function appropriately
    axis_acc_sensor();

// Declaration of set values method
// port must be 0, 1 or 2 or default will be set
// baud rate must be 19200 or 38400 or default will be set
// max acceleration must be 10, 20 or 50 or defualt will be set
// note resolution: 10 = 0.02 m/s^2, 20 = 0.04 m/s^2, 50 = 0.1 m/s^2
// returns string stating whether values are sane
    std::string set_values(int port, int baud, int max_acc);

// Declaration of getter function methods
// all getter functions are const safe to ensure that members cannot be altered
// all fixed parameters
    std::string get_fixed_model() const;
    int get_fixed_sampling_time() const;
    int get_fixed_sampling_resolution() const;
// user defined parameters
    std::string get_port() const;
    int get_baud() const;
    int get_max_acceleration() const;

// Declaration of method to request data from the sensor
// when the function returns true the acceleration variables have been refreshed at a rate of 10hz
    bool request_data();

// Declaration of method to recieve data from the sensor
// returns a pointer to the acceleration array
    double* recieve_data();

// Private member which are only accessible from methods in class
private:

// read only variable containing the sensor model
    const std::string model_ = "HWE-XXL";

// read only variables containing both sampling time (Hz) and sampling resolution
    const int sampling_time_ = FIXED_SAMPLING_TIME;
    const int sampling_resolution_ = FIXED_SAMPLING_RESOLUTION;

// variables that will be set by the user using class methods for operation
// baud rate and max acceleration (m/s^2)
    std::string port_;
    int baud_;
    int max_acceleration_;

// double array that holds sampled acceleration data
// acceleration[0] = x, acceleration[1] = y, acceleration[2] = z,
    double acceleration[3];

// member that generates random data when when called
    double generate_random_data();
};

#endif // AXIS_ACCELEROMETER_SENSOR

