// Auto-generated. Do not edit!

// (in-package lama_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

let LamaObject = require('../msg/LamaObject.js');

//-----------------------------------------------------------

class GetLamaObjectRequest {
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
    // Serializes a message object of type GetLamaObjectRequest
    // Serialize message field [id]
    bufferOffset = _serializer.int32(obj.id, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetLamaObjectRequest
    let len;
    let data = new GetLamaObjectRequest(null);
    // Deserialize message field [id]
    data.id = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lama_msgs/GetLamaObjectRequest';
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
    const resolved = new GetLamaObjectRequest(null);
    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    return resolved;
    }
};

class GetLamaObjectResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.object = null;
    }
    else {
      if (initObj.hasOwnProperty('object')) {
        this.object = initObj.object
      }
      else {
        this.object = new LamaObject();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetLamaObjectResponse
    // Serialize message field [object]
    bufferOffset = LamaObject.serialize(obj.object, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetLamaObjectResponse
    let len;
    let data = new GetLamaObjectResponse(null);
    // Deserialize message field [object]
    data.object = LamaObject.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += LamaObject.getMessageSize(object.object);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lama_msgs/GetLamaObjectResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'eea5eb07a771e62f930c7318a67ee584';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    LamaObject object
    
    
    ================================================================================
    MSG: lama_msgs/LamaObject
    # id of lama object in the database, will be unique.
    # When adding a vertex into the database, this id will be ignored.
    int32 id
    
    # id of lama object in the world (usage is implementation specific).
    int32 id_in_world
    
    # name of object
    string name
    
    # emitter id and name.
    int32 emitter_id
    string emitter_name
    
    # type: "EDGE" or "VERTEX"
    int32 type
    int32 VERTEX = 1
    int32 EDGE = 2
    
    # for edges: start and end vertices
    # for vertices: not used
    int32[2] references
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetLamaObjectResponse(null);
    if (msg.object !== undefined) {
      resolved.object = LamaObject.Resolve(msg.object)
    }
    else {
      resolved.object = new LamaObject()
    }

    return resolved;
    }
};

module.exports = {
  Request: GetLamaObjectRequest,
  Response: GetLamaObjectResponse,
  md5sum() { return '7a0bd86202cd08076ac08c680a875047'; },
  datatype() { return 'lama_msgs/GetLamaObject'; }
};
