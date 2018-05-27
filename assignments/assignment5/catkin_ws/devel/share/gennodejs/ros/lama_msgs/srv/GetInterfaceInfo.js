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

let InterfaceInfo = require('../msg/InterfaceInfo.js');

//-----------------------------------------------------------

class GetInterfaceInfoRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.interface_name = null;
    }
    else {
      if (initObj.hasOwnProperty('interface_name')) {
        this.interface_name = initObj.interface_name
      }
      else {
        this.interface_name = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetInterfaceInfoRequest
    // Serialize message field [interface_name]
    bufferOffset = _serializer.string(obj.interface_name, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetInterfaceInfoRequest
    let len;
    let data = new GetInterfaceInfoRequest(null);
    // Deserialize message field [interface_name]
    data.interface_name = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.interface_name.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lama_msgs/GetInterfaceInfoRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e9193059f50f78fd19fabc1ca461cc94';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    string interface_name
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetInterfaceInfoRequest(null);
    if (msg.interface_name !== undefined) {
      resolved.interface_name = msg.interface_name;
    }
    else {
      resolved.interface_name = ''
    }

    return resolved;
    }
};

class GetInterfaceInfoResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.interface_info = null;
    }
    else {
      if (initObj.hasOwnProperty('interface_info')) {
        this.interface_info = initObj.interface_info
      }
      else {
        this.interface_info = new InterfaceInfo();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetInterfaceInfoResponse
    // Serialize message field [interface_info]
    bufferOffset = InterfaceInfo.serialize(obj.interface_info, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetInterfaceInfoResponse
    let len;
    let data = new GetInterfaceInfoResponse(null);
    // Deserialize message field [interface_info]
    data.interface_info = InterfaceInfo.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += InterfaceInfo.getMessageSize(object.interface_info);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lama_msgs/GetInterfaceInfoResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '92e25680fddd79b010a79d7ab898da11';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    InterfaceInfo interface_info
    
    
    ================================================================================
    MSG: lama_msgs/InterfaceInfo
    # Interface name.
    string interface_name
    
    # The type of message associated with the interface.
    string message_type
    
    # The name of the associated service for getting a message.
    string get_service_name
    
    # The service message of the service for getting a message.
    string get_service_type
    
    # The name of the associated service for setting a message.
    string set_service_name
    
    # The service message of the service for setting a message.
    string set_service_type
    
    string interface_type
    
    # Timestamp of the last added message through this interface.
    time timestamp
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetInterfaceInfoResponse(null);
    if (msg.interface_info !== undefined) {
      resolved.interface_info = InterfaceInfo.Resolve(msg.interface_info)
    }
    else {
      resolved.interface_info = new InterfaceInfo()
    }

    return resolved;
    }
};

module.exports = {
  Request: GetInterfaceInfoRequest,
  Response: GetInterfaceInfoResponse,
  md5sum() { return '88018d5bbc756bb20b9d16e277b1cdc7'; },
  datatype() { return 'lama_msgs/GetInterfaceInfo'; }
};
