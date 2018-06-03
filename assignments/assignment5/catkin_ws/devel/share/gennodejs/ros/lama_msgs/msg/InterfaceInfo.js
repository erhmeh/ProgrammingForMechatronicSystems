// Auto-generated. Do not edit!

// (in-package lama_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class InterfaceInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.interface_name = null;
      this.message_type = null;
      this.get_service_name = null;
      this.get_service_type = null;
      this.set_service_name = null;
      this.set_service_type = null;
      this.interface_type = null;
      this.timestamp = null;
    }
    else {
      if (initObj.hasOwnProperty('interface_name')) {
        this.interface_name = initObj.interface_name
      }
      else {
        this.interface_name = '';
      }
      if (initObj.hasOwnProperty('message_type')) {
        this.message_type = initObj.message_type
      }
      else {
        this.message_type = '';
      }
      if (initObj.hasOwnProperty('get_service_name')) {
        this.get_service_name = initObj.get_service_name
      }
      else {
        this.get_service_name = '';
      }
      if (initObj.hasOwnProperty('get_service_type')) {
        this.get_service_type = initObj.get_service_type
      }
      else {
        this.get_service_type = '';
      }
      if (initObj.hasOwnProperty('set_service_name')) {
        this.set_service_name = initObj.set_service_name
      }
      else {
        this.set_service_name = '';
      }
      if (initObj.hasOwnProperty('set_service_type')) {
        this.set_service_type = initObj.set_service_type
      }
      else {
        this.set_service_type = '';
      }
      if (initObj.hasOwnProperty('interface_type')) {
        this.interface_type = initObj.interface_type
      }
      else {
        this.interface_type = '';
      }
      if (initObj.hasOwnProperty('timestamp')) {
        this.timestamp = initObj.timestamp
      }
      else {
        this.timestamp = {secs: 0, nsecs: 0};
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type InterfaceInfo
    // Serialize message field [interface_name]
    bufferOffset = _serializer.string(obj.interface_name, buffer, bufferOffset);
    // Serialize message field [message_type]
    bufferOffset = _serializer.string(obj.message_type, buffer, bufferOffset);
    // Serialize message field [get_service_name]
    bufferOffset = _serializer.string(obj.get_service_name, buffer, bufferOffset);
    // Serialize message field [get_service_type]
    bufferOffset = _serializer.string(obj.get_service_type, buffer, bufferOffset);
    // Serialize message field [set_service_name]
    bufferOffset = _serializer.string(obj.set_service_name, buffer, bufferOffset);
    // Serialize message field [set_service_type]
    bufferOffset = _serializer.string(obj.set_service_type, buffer, bufferOffset);
    // Serialize message field [interface_type]
    bufferOffset = _serializer.string(obj.interface_type, buffer, bufferOffset);
    // Serialize message field [timestamp]
    bufferOffset = _serializer.time(obj.timestamp, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type InterfaceInfo
    let len;
    let data = new InterfaceInfo(null);
    // Deserialize message field [interface_name]
    data.interface_name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [message_type]
    data.message_type = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [get_service_name]
    data.get_service_name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [get_service_type]
    data.get_service_type = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [set_service_name]
    data.set_service_name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [set_service_type]
    data.set_service_type = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [interface_type]
    data.interface_type = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [timestamp]
    data.timestamp = _deserializer.time(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.interface_name.length;
    length += object.message_type.length;
    length += object.get_service_name.length;
    length += object.get_service_type.length;
    length += object.set_service_name.length;
    length += object.set_service_type.length;
    length += object.interface_type.length;
    return length + 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lama_msgs/InterfaceInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '156de5bd66b7a123b19f5a2142f26e8c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new InterfaceInfo(null);
    if (msg.interface_name !== undefined) {
      resolved.interface_name = msg.interface_name;
    }
    else {
      resolved.interface_name = ''
    }

    if (msg.message_type !== undefined) {
      resolved.message_type = msg.message_type;
    }
    else {
      resolved.message_type = ''
    }

    if (msg.get_service_name !== undefined) {
      resolved.get_service_name = msg.get_service_name;
    }
    else {
      resolved.get_service_name = ''
    }

    if (msg.get_service_type !== undefined) {
      resolved.get_service_type = msg.get_service_type;
    }
    else {
      resolved.get_service_type = ''
    }

    if (msg.set_service_name !== undefined) {
      resolved.set_service_name = msg.set_service_name;
    }
    else {
      resolved.set_service_name = ''
    }

    if (msg.set_service_type !== undefined) {
      resolved.set_service_type = msg.set_service_type;
    }
    else {
      resolved.set_service_type = ''
    }

    if (msg.interface_type !== undefined) {
      resolved.interface_type = msg.interface_type;
    }
    else {
      resolved.interface_type = ''
    }

    if (msg.timestamp !== undefined) {
      resolved.timestamp = msg.timestamp;
    }
    else {
      resolved.timestamp = {secs: 0, nsecs: 0}
    }

    return resolved;
    }
};

module.exports = InterfaceInfo;
