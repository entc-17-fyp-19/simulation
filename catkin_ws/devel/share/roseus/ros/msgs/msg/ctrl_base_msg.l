;; Auto-generated. Do not edit!


(when (boundp 'msgs::ctrl_base_msg)
  (if (not (find-package "MSGS"))
    (make-package "MSGS"))
  (shadow 'ctrl_base_msg (find-package "MSGS")))
(unless (find-package "MSGS::CTRL_BASE_MSG")
  (make-package "MSGS::CTRL_BASE_MSG"))

(in-package "ROS")
;;//! \htmlinclude ctrl_base_msg.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass msgs::ctrl_base_msg
  :super ros::object
  :slots (_stop _angle ))

(defmethod msgs::ctrl_base_msg
  (:init
   (&key
    ((:stop __stop) 0)
    ((:angle __angle) (instance geometry_msgs::Quaternion :init))
    )
   (send-super :init)
   (setq _stop (round __stop))
   (setq _angle __angle)
   self)
  (:stop
   (&optional __stop)
   (if __stop (setq _stop __stop)) _stop)
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
    ;; uint8 _stop
    1
    ;; geometry_msgs/Quaternion _angle
    (send _angle :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _stop
       (write-byte _stop s)
     ;; geometry_msgs/Quaternion _angle
       (send _angle :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _stop
     (setq _stop (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; geometry_msgs/Quaternion _angle
     (send _angle :deserialize buf ptr-) (incf ptr- (send _angle :serialization-length))
   ;;
   self)
  )

(setf (get msgs::ctrl_base_msg :md5sum-) "2d61acf417dc0ac2964af53176a435fb")
(setf (get msgs::ctrl_base_msg :datatype-) "msgs/ctrl_base_msg")
(setf (get msgs::ctrl_base_msg :definition-)
      "uint8 stop
geometry_msgs/Quaternion angle

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :msgs/ctrl_base_msg "2d61acf417dc0ac2964af53176a435fb")


