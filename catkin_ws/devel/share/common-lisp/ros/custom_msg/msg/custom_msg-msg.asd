
(cl:in-package :asdf)

(defsystem "custom_msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ctrl_base" :depends-on ("_package_ctrl_base"))
    (:file "_package_ctrl_base" :depends-on ("_package"))
  ))