// Auto-generated. Do not edit!

// (in-package lama_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Crossing = require('../msg/Crossing.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class SetCrossingRequest {
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
        this.descriptor = new Crossing();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetCrossingRequest
    // Serialize message field [descriptor]
    bufferOffset = Crossing.serialize(obj.descriptor, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetCrossingRequest
    let len;
    let data = new SetCrossingRequest(null);
    // Deserialize message field [descriptor]
    data.descriptor = Crossing.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += Crossing.getMessageSize(object.descriptor);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lama_msgs/SetCrossingRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '753047a0f3e0e7bbdd77b36b85512c99';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Crossing descriptor
    
    ================================================================================
    MSG: lama_msgs/Crossing
    # The main aim of a crossing is to store frontier information.
    
    # Crossing center.
    geometry_msgs/Point center
    
    # Crossing radius.
    float32 radius
    
    # Max. range of the data used to compute the crossing.
    float32 max_range
    
    Frontier[] frontiers
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: lama_msgs/Frontier
    # Frontier is a line segment through which a robot can go.
    
    # First point
    geometry_msgs/Point p1
    
    # Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.
    geometry_msgs/Point p2
    
    # Segment length, i.e. width of free space
    float32 width
    
    # Angle between x-axis and line between origin and frontier middle. Where x-axis
    # and origin refer to the data from which the frontier is computed, in general a LaserScan.
    float32 angle
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetCrossingRequest(null);
    if (msg.descriptor !== undefined) {
      resolved.descriptor = Crossing.Resolve(msg.descriptor)
    }
    else {
      resolved.descriptor = new Crossing()
    }

    return resolved;
    }
};

class SetCrossingResponse {
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
    // Serializes a message object of type SetCrossingResponse
    // Serialize message field [id]
    bufferOffset = _serializer.int32(obj.id, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetCrossingResponse
    let len;
    let data = new SetCrossingResponse(null);
    // Deserialize message field [id]
    data.id = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lama_msgs/SetCrossingResponse';
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
    const resolved = new SetCrossingResponse(null);
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
  Request: SetCrossingRequest,
  Response: SetCrossingResponse,
  md5sum() { return '400039bcfb4fed83ffb70a6297f272bc'; },
  datatype() { return 'lama_msgs/SetCrossing'; }
};
