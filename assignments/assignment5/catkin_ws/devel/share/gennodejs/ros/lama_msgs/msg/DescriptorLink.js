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

class DescriptorLink {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.object_id = null;
      this.descriptor_id = null;
      this.interface_name = null;
    }
    else {
      if (initObj.hasOwnProperty('object_id')) {
        this.object_id = initObj.object_id
      }
      else {
        this.object_id = 0;
      }
      if (initObj.hasOwnProperty('descriptor_id')) {
        this.descriptor_id = initObj.descriptor_id
      }
      else {
        this.descriptor_id = 0;
      }
      if (initObj.hasOwnProperty('interface_name')) {
        this.interface_name = initObj.interface_name
      }
      else {
        this.interface_name = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DescriptorLink
    // Serialize message field [object_id]
    bufferOffset = _serializer.int32(obj.object_id, buffer, bufferOffset);
    // Serialize message field [descriptor_id]
    bufferOffset = _serializer.int32(obj.descriptor_id, buffer, bufferOffset);
    // Serialize message field [interface_name]
    bufferOffset = _serializer.string(obj.interface_name, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DescriptorLink
    let len;
    let data = new DescriptorLink(null);
    // Deserialize message field [object_id]
    data.object_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [descriptor_id]
    data.descriptor_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [interface_name]
    data.interface_name = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.interface_name.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lama_msgs/DescriptorLink';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7f6d6af0c2f5ed48be6d42a3bb530828';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # A DescriptorLink is a bond between a Lama object and a descriptor.
    
    # Id of the Lama object associated with the descriptor (in the database).
    int32 object_id
    
    # Id of the associated descriptor (in the database).
    int32 descriptor_id 
    
    # Interface name which also identifies the descriptor type.
    string interface_name
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DescriptorLink(null);
    if (msg.object_id !== undefined) {
      resolved.object_id = msg.object_id;
    }
    else {
      resolved.object_id = 0
    }

    if (msg.descriptor_id !== undefined) {
      resolved.descriptor_id = msg.descriptor_id;
    }
    else {
      resolved.descriptor_id = 0
    }

    if (msg.interface_name !== undefined) {
      resolved.interface_name = msg.interface_name;
    }
    else {
      resolved.interface_name = ''
    }

    return resolved;
    }
};

module.exports = DescriptorLink;
