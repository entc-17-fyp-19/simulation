; Auto-generated. Do not edit!


(cl:in-package msgs-msg)


;//! \htmlinclude ctrl_base_msg.msg.html

(cl:defclass <ctrl_base_msg> (roslisp-msg-protocol:ros-message)
  ((stop
    :reader stop
    :initarg :stop
    :type cl:fixnum
    :initform 0)
   (angle
    :reader angle
    :initarg :angle
    :type geometry_msgs-msg:Quaternion
    :initform (cl:make-instance 'geometry_msgs-msg:Quaternion)))
)

(cl:defclass ctrl_base_msg (<ctrl_base_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ctrl_base_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ctrl_base_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msgs-msg:<ctrl_base_msg> is deprecated: use msgs-msg:ctrl_base_msg instead.")))

(cl:ensure-generic-function 'stop-val :lambda-list '(m))
(cl:defmethod stop-val ((m <ctrl_base_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgs-msg:stop-val is deprecated.  Use msgs-msg:stop instead.")
  (stop m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <ctrl_base_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgs-msg:angle-val is deprecated.  Use msgs-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ctrl_base_msg>) ostream)
  "Serializes a message object of type '<ctrl_base_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'stop)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'angle) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ctrl_base_msg>) istream)
  "Deserializes a message object of type '<ctrl_base_msg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'stop)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'angle) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ctrl_base_msg>)))
  "Returns string type for a message object of type '<ctrl_base_msg>"
  "msgs/ctrl_base_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ctrl_base_msg)))
  "Returns string type for a message object of type 'ctrl_base_msg"
  "msgs/ctrl_base_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ctrl_base_msg>)))
  "Returns md5sum for a message object of type '<ctrl_base_msg>"
  "2d61acf417dc0ac2964af53176a435fb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ctrl_base_msg)))
  "Returns md5sum for a message object of type 'ctrl_base_msg"
  "2d61acf417dc0ac2964af53176a435fb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ctrl_base_msg>)))
  "Returns full string definition for message of type '<ctrl_base_msg>"
  (cl:format cl:nil "uint8 stop~%geometry_msgs/Quaternion angle~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ctrl_base_msg)))
  "Returns full string definition for message of type 'ctrl_base_msg"
  (cl:format cl:nil "uint8 stop~%geometry_msgs/Quaternion angle~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ctrl_base_msg>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'angle))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ctrl_base_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'ctrl_base_msg
    (cl:cons ':stop (stop msg))
    (cl:cons ':angle (angle msg))
))
