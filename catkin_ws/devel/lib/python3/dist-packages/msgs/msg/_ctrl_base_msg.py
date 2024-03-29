# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from msgs/ctrl_base_msg.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class ctrl_base_msg(genpy.Message):
  _md5sum = "2d61acf417dc0ac2964af53176a435fb"
  _type = "msgs/ctrl_base_msg"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint8 stop
geometry_msgs/Quaternion angle

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
"""
  __slots__ = ['stop','angle']
  _slot_types = ['uint8','geometry_msgs/Quaternion']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       stop,angle

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ctrl_base_msg, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.stop is None:
        self.stop = 0
      if self.angle is None:
        self.angle = geometry_msgs.msg.Quaternion()
    else:
      self.stop = 0
      self.angle = geometry_msgs.msg.Quaternion()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_B4d().pack(_x.stop, _x.angle.x, _x.angle.y, _x.angle.z, _x.angle.w))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.angle is None:
        self.angle = geometry_msgs.msg.Quaternion()
      end = 0
      _x = self
      start = end
      end += 33
      (_x.stop, _x.angle.x, _x.angle.y, _x.angle.z, _x.angle.w,) = _get_struct_B4d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_B4d().pack(_x.stop, _x.angle.x, _x.angle.y, _x.angle.z, _x.angle.w))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.angle is None:
        self.angle = geometry_msgs.msg.Quaternion()
      end = 0
      _x = self
      start = end
      end += 33
      (_x.stop, _x.angle.x, _x.angle.y, _x.angle.z, _x.angle.w,) = _get_struct_B4d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B4d = None
def _get_struct_B4d():
    global _struct_B4d
    if _struct_B4d is None:
        _struct_B4d = struct.Struct("<B4d")
    return _struct_B4d
