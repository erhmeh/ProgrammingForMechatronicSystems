
(cl:in-package :asdf)

(defsystem "lama_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Crossing" :depends-on ("_package_Crossing"))
    (:file "_package_Crossing" :depends-on ("_package"))
    (:file "DescriptorLink" :depends-on ("_package_DescriptorLink"))
    (:file "_package_DescriptorLink" :depends-on ("_package"))
    (:file "Frontier" :depends-on ("_package_Frontier"))
    (:file "_package_Frontier" :depends-on ("_package"))
    (:file "InterfaceInfo" :depends-on ("_package_InterfaceInfo"))
    (:file "_package_InterfaceInfo" :depends-on ("_package"))
    (:file "LamaObject" :depends-on ("_package_LamaObject"))
    (:file "_package_LamaObject" :depends-on ("_package"))
    (:file "PlaceProfile" :depends-on ("_package_PlaceProfile"))
    (:file "_package_PlaceProfile" :depends-on ("_package"))
  ))