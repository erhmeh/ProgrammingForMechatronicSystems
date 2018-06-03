;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::GetInterfaceInfo)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'GetInterfaceInfo (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::GETINTERFACEINFO")
  (make-package "LAMA_MSGS::GETINTERFACEINFO"))
(unless (find-package "LAMA_MSGS::GETINTERFACEINFOREQUEST")
  (make-package "LAMA_MSGS::GETINTERFACEINFOREQUEST"))
(unless (find-package "LAMA_MSGS::GETINTERFACEINFORESPONSE")
  (make-package "LAMA_MSGS::GETINTERFACEINFORESPONSE"))

(in-package "ROS")





(defclass lama_msgs::GetInterfaceInfoRequest
  :super ros::object
  :slots (_interface_name ))

(defmethod lama_msgs::GetInterfaceInfoRequest
  (:init
   (&key
    ((:interface_name __interface_name) "")
    )
   (send-super :init)
   (setq _interface_name (string __interface_name))
   self)
  (:interface_name
   (&optional __interface_name)
   (if __interface_name (setq _interface_name __interface_name)) _interface_name)
  (:serialization-length
   ()
   (+
    ;; string _interface_name
    4 (length _interface_name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _interface_name
       (write-long (length _interface_name) s) (princ _interface_name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _interface_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _interface_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass lama_msgs::GetInterfaceInfoResponse
  :super ros::object
  :slots (_interface_info ))

(defmethod lama_msgs::GetInterfaceInfoResponse
  (:init
   (&key
    ((:interface_info __interface_info) (instance lama_msgs::InterfaceInfo :init))
    )
   (send-super :init)
   (setq _interface_info __interface_info)
   self)
  (:interface_info
   (&rest __interface_info)
   (if (keywordp (car __interface_info))
       (send* _interface_info __interface_info)
     (progn
       (if __interface_info (setq _interface_info (car __interface_info)))
       _interface_info)))
  (:serialization-length
   ()
   (+
    ;; lama_msgs/InterfaceInfo _interface_info
    (send _interface_info :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; lama_msgs/InterfaceInfo _interface_info
       (send _interface_info :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; lama_msgs/InterfaceInfo _interface_info
     (send _interface_info :deserialize buf ptr-) (incf ptr- (send _interface_info :serialization-length))
   ;;
   self)
  )

(defclass lama_msgs::GetInterfaceInfo
  :super ros::object
  :slots ())

(setf (get lama_msgs::GetInterfaceInfo :md5sum-) "88018d5bbc756bb20b9d16e277b1cdc7")
(setf (get lama_msgs::GetInterfaceInfo :datatype-) "lama_msgs/GetInterfaceInfo")
(setf (get lama_msgs::GetInterfaceInfo :request) lama_msgs::GetInterfaceInfoRequest)
(setf (get lama_msgs::GetInterfaceInfo :response) lama_msgs::GetInterfaceInfoResponse)

(defmethod lama_msgs::GetInterfaceInfoRequest
  (:response () (instance lama_msgs::GetInterfaceInfoResponse :init)))

(setf (get lama_msgs::GetInterfaceInfoRequest :md5sum-) "88018d5bbc756bb20b9d16e277b1cdc7")
(setf (get lama_msgs::GetInterfaceInfoRequest :datatype-) "lama_msgs/GetInterfaceInfoRequest")
(setf (get lama_msgs::GetInterfaceInfoRequest :definition-)
      "
string interface_name
---
InterfaceInfo interface_info


================================================================================
MSG: lama_msgs/InterfaceInfo
# Interface name.
string interface_name

# The type of message associated with the interface.
string message_type

# The name of the associated service for getting a message.
string get_service_name

# The service message of the service for getting a message.
string get_service_type

# The name of the associated service for setting a message.
string set_service_name

# The service message of the service for setting a message.
string set_service_type

string interface_type

# Timestamp of the last added message through this interface.
time timestamp
")

(setf (get lama_msgs::GetInterfaceInfoResponse :md5sum-) "88018d5bbc756bb20b9d16e277b1cdc7")
(setf (get lama_msgs::GetInterfaceInfoResponse :datatype-) "lama_msgs/GetInterfaceInfoResponse")
(setf (get lama_msgs::GetInterfaceInfoResponse :definition-)
      "
string interface_name
---
InterfaceInfo interface_info


================================================================================
MSG: lama_msgs/InterfaceInfo
# Interface name.
string interface_name

# The type of message associated with the interface.
string message_type

# The name of the associated service for getting a message.
string get_service_name

# The service message of the service for getting a message.
string get_service_type

# The name of the associated service for setting a message.
string set_service_name

# The service message of the service for setting a message.
string set_service_type

string interface_type

# Timestamp of the last added message through this interface.
time timestamp
")



(provide :lama_msgs/GetInterfaceInfo "88018d5bbc756bb20b9d16e277b1cdc7")


