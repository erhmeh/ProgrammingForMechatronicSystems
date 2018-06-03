
(cl:in-package :asdf)

(defsystem "lama_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :lama_msgs-msg
)
  :components ((:file "_package")
    (:file "GetCrossing" :depends-on ("_package_GetCrossing"))
    (:file "_package_GetCrossing" :depends-on ("_package"))
    (:file "GetInterfaceInfo" :depends-on ("_package_GetInterfaceInfo"))
    (:file "_package_GetInterfaceInfo" :depends-on ("_package"))
    (:file "GetLamaObject" :depends-on ("_package_GetLamaObject"))
    (:file "_package_GetLamaObject" :depends-on ("_package"))
    (:file "GetPlaceProfile" :depends-on ("_package_GetPlaceProfile"))
    (:file "_package_GetPlaceProfile" :depends-on ("_package"))
    (:file "SetCrossing" :depends-on ("_package_SetCrossing"))
    (:file "_package_SetCrossing" :depends-on ("_package"))
    (:file "SetLamaObject" :depends-on ("_package_SetLamaObject"))
    (:file "_package_SetLamaObject" :depends-on ("_package"))
    (:file "SetPlaceProfile" :depends-on ("_package_SetPlaceProfile"))
    (:file "_package_SetPlaceProfile" :depends-on ("_package"))
  ))