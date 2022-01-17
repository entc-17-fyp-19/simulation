;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::ctrl_base)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'ctrl_base (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::CTRL_BASE")
  (make-package "CUSTOM_MSG::CTRL_BASE"))

(in-package "ROS")
;;//! \htmlinclude ctrl_base.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass custom_msg::ctrl_base
  :super ros::object
  :slots (_ctrl_base _angle ))

(defmethod custom_msg::ctrl_base
  (:init
   (&key
    ((:ctrl_base __ctrl_base) (instance std_msgs::UInt8 :init))
    ((:angle __angle) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _ctrl_base __ctrl_base)
   (setq _angle __angle)
   self)
  (:ctrl_base
   (&rest __ctrl_base)
   (if (keywordp (car __ctrl_base))
       (send* _ctrl_base __ctrl_base)
     (progn
       (if __ctrl_base (setq _ctrl_base (car __ctrl_base)))
       _ctrl_base)))
  (:angle
   (&rest __angle)
   (if (keywordp (car __angle))
       (send* _angle __angle)
     (progn
       (if __angle (setq _angle (car __angle)))
       _angle)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/UInt8 _ctrl_base
    (send _ctrl_base :serialization-length)
    ;; std_msgs/Float32 _angle
    (send _angle :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/UInt8 _ctrl_base
       (send _ctrl_base :serialize s)
     ;; std_msgs/Float32 _angle
       (send _angle :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/UInt8 _ctrl_base
     (send _ctrl_base :deserialize buf ptr-) (incf ptr- (send _ctrl_base :serialization-length))
   ;; std_msgs/Float32 _angle
     (send _angle :deserialize buf ptr-) (incf ptr- (send _angle :serialization-length))
   ;;
   self)
  )

(setf (get custom_msg::ctrl_base :md5sum-) "4eeae671ad76ddd32fa58c4dacb24993")
(setf (get custom_msg::ctrl_base :datatype-) "custom_msg/ctrl_base")
(setf (get custom_msg::ctrl_base :definition-)
      "std_msgs/UInt8 ctrl_base
std_msgs/Float32 angle

================================================================================
MSG: std_msgs/UInt8
uint8 data

================================================================================
MSG: std_msgs/Float32
float32 data
")



(provide :custom_msg/ctrl_base "4eeae671ad76ddd32fa58c4dacb24993")


