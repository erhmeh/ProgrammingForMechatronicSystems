// Auto-generated. Do not edit!

// (in-package lama_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let PlaceProfile = require('../msg/PlaceProfile.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class SetPlaceProfileRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.descriptor = null;
    }
    else {
      if (initObj.hasOwnProperty('descriptor')) {
        this.descriptor = initObj.descriptor
      }
      else {
        this.descriptor = new PlaceProfile();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetPlaceProfileRequest
    // Serialize message field [descriptor]
    bufferOffset = PlaceProfile.serialize(obj.descriptor, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetPlaceProfileRequest
    let len;
    let data = new SetPlaceProfileRequest(null);
    // Deserialize message field [descriptor]
    data.descriptor = PlaceProfile.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += PlaceProfile.getMessageSize(object.descriptor);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lama_msgs/SetPlaceProfileRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f528bce67fe2dc9e2ab90ef5f1e58071';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    PlaceProfile descriptor
    
    ================================================================================
    MSG: lama_msgs/PlaceProfile
    # 2D Description of a place by some points at obstacle borders
    # The difference with a LaserScan is that some segments can
    # be marked as to be excluded. Such segments will be the segments
    # where the range is the maximum range of the LaserSCan or
    # borders between free and unknown pixels of a costmap.
    
    Header header
    
    geometry_msgs/Polygon polygon
    
    # Segments to exclude, segment i is between point i and i+1.
    # The last segment is between points (n-1) and 0, where n is the number of points.
    int32[] exclude_segments
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Polygon
    #A specification of a polygon where the first and last points are assumed to be connected
    Point32[] points
    
    ================================================================================
    MSG: geometry_msgs/Point32
    # This contains the position of a point in free space(with 32 bits of precision).
    # It is recommeded to use Point wherever possible instead of Point32.  
    # 
    # This recommendation is to promote interoperability.  
    #
    # This message is designed to take up less space when sending
    # lots of points at once, as in the case of a PointCloud.  
    
    float32 x
    float32 y
    float32 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetPlaceProfileRequest(null);
    if (msg.descriptor !== undefined) {
      resolved.descriptor = PlaceProfile.Resolve(msg.descriptor)
    }
    else {
      resolved.descriptor = new PlaceProfile()
    }

    return resolved;
    }
};

class SetPlaceProfileResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.id = null;
    }
    else {
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetPlaceProfileResponse
    // Serialize message field [id]
    bufferOffset = _serializer.int32(obj.id, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetPlaceProfileResponse
    let len;
    let data = new SetPlaceProfileResponse(null);
    // Deserialize message field [id]
    data.id = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lama_msgs/SetPlaceProfileResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c5e4a7d59c68f74eabcec876a00216aa';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 id
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetPlaceProfileResponse(null);
    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: SetPlaceProfileRequest,
  Response: SetPlaceProfileResponse,
  md5sum() { return '33f8b6a8c5bc01cf725509cfd487af55'; },
  datatype() { return 'lama_msgs/SetPlaceProfile'; }
};
