; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude ctrl_base.msg.html

(cl:defclass <ctrl_base> (roslisp-msg-protocol:ros-message)
  ((ctrl_base
    :reader ctrl_base
    :initarg :ctrl_base
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (angle
    :reader angle
    :initarg :angle
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass ctrl_base (<ctrl_base>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ctrl_base>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ctrl_base)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<ctrl_base> is deprecated: use custom_msg-msg:ctrl_base instead.")))

(cl:ensure-generic-function 'ctrl_base-val :lambda-list '(m))
(cl:defmethod ctrl_base-val ((m <ctrl_base>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:ctrl_base-val is deprecated.  Use custom_msg-msg:ctrl_base instead.")
  (ctrl_base m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <ctrl_base>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:angle-val is deprecated.  Use custom_msg-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ctrl_base>) ostream)
  "Serializes a message object of type '<ctrl_base>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ctrl_base) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'angle) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ctrl_base>) istream)
  "Deserializes a message object of type '<ctrl_base>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ctrl_base) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'angle) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ctrl_base>)))
  "Returns string type for a message object of type '<ctrl_base>"
  "custom_msg/ctrl_base")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ctrl_base)))
  "Returns string type for a message object of type 'ctrl_base"
  "custom_msg/ctrl_base")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ctrl_base>)))
  "Returns md5sum for a message object of type '<ctrl_base>"
  "4eeae671ad76ddd32fa58c4dacb24993")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ctrl_base)))
  "Returns md5sum for a message object of type 'ctrl_base"
  "4eeae671ad76ddd32fa58c4dacb24993")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ctrl_base>)))
  "Returns full string definition for message of type '<ctrl_base>"
  (cl:format cl:nil "std_msgs/UInt8 ctrl_base~%std_msgs/Float32 angle~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ctrl_base)))
  "Returns full string definition for message of type 'ctrl_base"
  (cl:format cl:nil "std_msgs/UInt8 ctrl_base~%std_msgs/Float32 angle~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ctrl_base>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ctrl_base))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'angle))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ctrl_base>))
  "Converts a ROS message object to a list"
  (cl:list 'ctrl_base
    (cl:cons ':ctrl_base (ctrl_base msg))
    (cl:cons ':angle (angle msg))
))
