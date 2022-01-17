
(cl:in-package :asdf)

(defsystem "msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "ctrl_base_msg" :depends-on ("_package_ctrl_base_msg"))
    (:file "_package_ctrl_base_msg" :depends-on ("_package"))
  ))