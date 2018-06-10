#include "Radar.h"

// Constructor initialies the class object //////////////////////////////////////////////////////////////////////////

// Initialise all the required variables to enable connecting to the Sonar sensor //
Radar::Radar()
{
    // Initialises data parameters for Radar object //
    _model = RADAR_MODEL; // "RAD-001"

    _baud = RADAR_DEFAULT_BAUD; // Initialises to 38400
    _defaultBaud = RADAR_DEFAULT_BAUD;  // 38400
    _baudOptions = {RADAR_DEFAULT_BAUD, RADAR_ADDITIONAL_BAUD, -1}; // 38400 and 115200

    _port = RADAR_DEFAULT_PORT; // Initialises to 0
    _defaultPort = RADAR_DEFAULT_PORT; // 0
    _portOptions = {RADAR_DEFAULT_PORT, RADAR_ADDITIONAL_PORT1, RADAR_ADDITIONAL_PORT2, -1}; // 0 and 1 and 2

    _fieldOfView = RADAR_DEFAULT_FIELD_OF_VIEW; // Initialises to (20 degrees)
    _defaultFieldOfView = RADAR_DEFAULT_FIELD_OF_VIEW; // (20 degrees)
    _fieldOfViewOptions = {RADAR_DEFAULT_FIELD_OF_VIEW, RADAR_ADDITIONAL_FIELD_OF_VIEW, -1}; // (20 degrees) and (40 degrees)

    _angularResolution = RADAR_DEFAULT_ANGULAR_RESOLUTION; // Only one value within the field of view thus, (_angularResolution = _fieldOfView)
    _defaultAngluarResolution = RADAR_DEFAULT_ANGULAR_RESOLUTION;
    _angularResolutionOptions = {RADAR_DEFAULT_ANGULAR_RESOLUTION, RADAR_ADDITIONAL_ANGULAR_RESOLUTION, -1};

    _maxDistance = RADAR_DEFAULT_MAX_DISTANCE; // Initialises to (10 meters)

    _minDistance = RADAR_DEFAULT_MIN_DISTANCE; // Initialises to (0.2 meters)

    _dataRate = RADAR_DEFAULT_DATA_RATE; // Initialises to (10 Hz)
}
