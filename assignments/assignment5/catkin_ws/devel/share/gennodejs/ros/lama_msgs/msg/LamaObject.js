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

class LamaObject {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.id = null;
      this.id_in_world = null;
      this.name = null;
      this.emitter_id = null;
      this.emitter_name = null;
      this.type = null;
      this.references = null;
    }
    else {
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('id_in_world')) {
        this.id_in_world = initObj.id_in_world
      }
      else {
        this.id_in_world = 0;
      }
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = '';
      }
      if (initObj.hasOwnProperty('emitter_id')) {
        this.emitter_id = initObj.emitter_id
      }
      else {
        this.emitter_id = 0;
      }
      if (initObj.hasOwnProperty('emitter_name')) {
        this.emitter_name = initObj.emitter_name
      }
      else {
        this.emitter_name = '';
      }
      if (initObj.hasOwnProperty('type')) {
        this.type = initObj.type
      }
      else {
        this.type = 0;
      }
      if (initObj.hasOwnProperty('references')) {
        this.references = initObj.references
      }
      else {
        this.references = new Array(2).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LamaObject
    // Serialize message field [id]
    bufferOffset = _serializer.int32(obj.id, buffer, bufferOffset);
    // Serialize message field [id_in_world]
    bufferOffset = _serializer.int32(obj.id_in_world, buffer, bufferOffset);
    // Serialize message field [name]
    bufferOffset = _serializer.string(obj.name, buffer, bufferOffset);
    // Serialize message field [emitter_id]
    bufferOffset = _serializer.int32(obj.emitter_id, buffer, bufferOffset);
    // Serialize message field [emitter_name]
    bufferOffset = _serializer.string(obj.emitter_name, buffer, bufferOffset);
    // Serialize message field [type]
    bufferOffset = _serializer.int32(obj.type, buffer, bufferOffset);
    // Check that the constant length array field [references] has the right length
    if (obj.references.length !== 2) {
      throw new Error('Unable to serialize array field references - length must be 2')
    }
    // Serialize message field [references]
    bufferOffset = _arraySerializer.int32(obj.references, buffer, bufferOffset, 2);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LamaObject
    let len;
    let data = new LamaObject(null);
    // Deserialize message field [id]
    data.id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [id_in_world]
    data.id_in_world = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [name]
    data.name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [emitter_id]
    data.emitter_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [emitter_name]
    data.emitter_name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [type]
    data.type = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [references]
    data.references = _arrayDeserializer.int32(buffer, bufferOffset, 2)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.name.length;
    length += object.emitter_name.length;
    return length + 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lama_msgs/LamaObject';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e2747a1741c10b06140b9673d9018102';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new LamaObject(null);
    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.id_in_world !== undefined) {
      resolved.id_in_world = msg.id_in_world;
    }
    else {
      resolved.id_in_world = 0
    }

    if (msg.name !== undefined) {
      resolved.name = msg.name;
    }
    else {
      resolved.name = ''
    }

    if (msg.emitter_id !== undefined) {
      resolved.emitter_id = msg.emitter_id;
    }
    else {
      resolved.emitter_id = 0
    }

    if (msg.emitter_name !== undefined) {
      resolved.emitter_name = msg.emitter_name;
    }
    else {
      resolved.emitter_name = ''
    }

    if (msg.type !== undefined) {
      resolved.type = msg.type;
    }
    else {
      resolved.type = 0
    }

    if (msg.references !== undefined) {
      resolved.references = msg.references;
    }
    else {
      resolved.references = new Array(2).fill(0)
    }

    return resolved;
    }
};

// Constants for message
LamaObject.Constants = {
  VERTEX: 1,
  EDGE: 2,
}

module.exports = LamaObject;
