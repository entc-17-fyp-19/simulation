// Auto-generated. Do not edit!

// (in-package msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class ctrl_base_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stop = null;
      this.angle = null;
    }
    else {
      if (initObj.hasOwnProperty('stop')) {
        this.stop = initObj.stop
      }
      else {
        this.stop = 0;
      }
      if (initObj.hasOwnProperty('angle')) {
        this.angle = initObj.angle
      }
      else {
        this.angle = new geometry_msgs.msg.Quaternion();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ctrl_base_msg
    // Serialize message field [stop]
    bufferOffset = _serializer.uint8(obj.stop, buffer, bufferOffset);
    // Serialize message field [angle]
    bufferOffset = geometry_msgs.msg.Quaternion.serialize(obj.angle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ctrl_base_msg
    let len;
    let data = new ctrl_base_msg(null);
    // Deserialize message field [stop]
    data.stop = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [angle]
    data.angle = geometry_msgs.msg.Quaternion.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 33;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msgs/ctrl_base_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2d61acf417dc0ac2964af53176a435fb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 stop
    geometry_msgs/Quaternion angle
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ctrl_base_msg(null);
    if (msg.stop !== undefined) {
      resolved.stop = msg.stop;
    }
    else {
      resolved.stop = 0
    }

    if (msg.angle !== undefined) {
      resolved.angle = geometry_msgs.msg.Quaternion.Resolve(msg.angle)
    }
    else {
      resolved.angle = new geometry_msgs.msg.Quaternion()
    }

    return resolved;
    }
};

module.exports = ctrl_base_msg;
