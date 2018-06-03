
(cl:in-package :asdf)

(defsystem "a5_help-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "RequestGoal" :depends-on ("_package_RequestGoal"))
    (:file "_package_RequestGoal" :depends-on ("_package"))
  ))