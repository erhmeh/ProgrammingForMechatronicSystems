#include "Sonar.h"

// Constructor initialies the class object //////////////////////////////////////////////////////////////////////////

// Initialise all the required variables to enable connecting to the Sonar sensor //
Sonar::Sonar()
{
    // Initialises data parameters for Sonar object //
    _model = SONAR_MODEL; // "SON-001"

    _baud = SONAR_DEFAULT_BAUD; // Initialises to 38400
    _defaultBaud = SONAR_DEFAULT_BAUD;  // 38400
    _baudOptions = {SONAR_DEFAULT_BAUD, SONAR_ADDITIONAL_BAUD, -1}; // 38400 and 115200

    _port = SONAR_DEFAULT_PORT; // Initialises to 0
    _defaultPort = SONAR_DEFAULT_PORT; // 0
    _portOptions = {SONAR_DEFAULT_PORT, SONAR_ADDITIONAL_PORT1, SONAR_ADDITIONAL_PORT2, -1}; // 0 and 1 and 2

    _fieldOfView = SONAR_DEFAULT_FIELD_OF_VIEW; // Initialises to (90 degrees)
    _defaultFieldOfView = SONAR_DEFAULT_FIELD_OF_VIEW; // (90 degrees)
    _fieldOfViewOptions = {SONAR_DEFAULT_FIELD_OF_VIEW, -1};

    _angularResolution = SONAR_DEFAULT_ANGULAR_RESOLUTION; // Initialises to (90 degrees)
    _defaultAngluarResolution = SONAR_DEFAULT_ANGULAR_RESOLUTION; // (90 degrees)
    _angularResolutionOptions = {SONAR_DEFAULT_ANGULAR_RESOLUTION, -1};

    _maxDistance = SONAR_DEFAULT_MAX_DISTANCE; // Initialises to (6 meters)

    _minDistance = SONAR_DEFAULT_MIN_DISTANCE; // Initialises to (0.2 meters)

    _dataRate = SONAR_DEFAULT_DATA_RATE; // Initialises to (3 Hz)
}
