// Auto-generated. Do not edit!

// (in-package custom_msg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ctrl_base {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ctrl_base = null;
      this.angle = null;
    }
    else {
      if (initObj.hasOwnProperty('ctrl_base')) {
        this.ctrl_base = initObj.ctrl_base
      }
      else {
        this.ctrl_base = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('angle')) {
        this.angle = initObj.angle
      }
      else {
        this.angle = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ctrl_base
    // Serialize message field [ctrl_base]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.ctrl_base, buffer, bufferOffset);
    // Serialize message field [angle]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.angle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ctrl_base
    let len;
    let data = new ctrl_base(null);
    // Deserialize message field [ctrl_base]
    data.ctrl_base = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [angle]
    data.angle = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg/ctrl_base';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4eeae671ad76ddd32fa58c4dacb24993';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/UInt8 ctrl_base
    std_msgs/Float32 angle
    
    ================================================================================
    MSG: std_msgs/UInt8
    uint8 data
    
    ================================================================================
    MSG: std_msgs/Float32
    float32 data
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ctrl_base(null);
    if (msg.ctrl_base !== undefined) {
      resolved.ctrl_base = std_msgs.msg.UInt8.Resolve(msg.ctrl_base)
    }
    else {
      resolved.ctrl_base = new std_msgs.msg.UInt8()
    }

    if (msg.angle !== undefined) {
      resolved.angle = std_msgs.msg.Float32.Resolve(msg.angle)
    }
    else {
      resolved.angle = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

module.exports = ctrl_base;
