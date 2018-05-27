;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::InterfaceInfo)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'InterfaceInfo (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::INTERFACEINFO")
  (make-package "LAMA_MSGS::INTERFACEINFO"))

(in-package "ROS")
;;//! \htmlinclude InterfaceInfo.msg.html


(defclass lama_msgs::InterfaceInfo
  :super ros::object
  :slots (_interface_name _message_type _get_service_name _get_service_type _set_service_name _set_service_type _interface_type _timestamp ))

(defmethod lama_msgs::InterfaceInfo
  (:init
   (&key
    ((:interface_name __interface_name) "")
    ((:message_type __message_type) "")
    ((:get_service_name __get_service_name) "")
    ((:get_service_type __get_service_type) "")
    ((:set_service_name __set_service_name) "")
    ((:set_service_type __set_service_type) "")
    ((:interface_type __interface_type) "")
    ((:timestamp __timestamp) (instance ros::time :init))
    )
   (send-super :init)
   (setq _interface_name (string __interface_name))
   (setq _message_type (string __message_type))
   (setq _get_service_name (string __get_service_name))
   (setq _get_service_type (string __get_service_type))
   (setq _set_service_name (string __set_service_name))
   (setq _set_service_type (string __set_service_type))
   (setq _interface_type (string __interface_type))
   (setq _timestamp __timestamp)
   self)
  (:interface_name
   (&optional __interface_name)
   (if __interface_name (setq _interface_name __interface_name)) _interface_name)
  (:message_type
   (&optional __message_type)
   (if __message_type (setq _message_type __message_type)) _message_type)
  (:get_service_name
   (&optional __get_service_name)
   (if __get_service_name (setq _get_service_name __get_service_name)) _get_service_name)
  (:get_service_type
   (&optional __get_service_type)
   (if __get_service_type (setq _get_service_type __get_service_type)) _get_service_type)
  (:set_service_name
   (&optional __set_service_name)
   (if __set_service_name (setq _set_service_name __set_service_name)) _set_service_name)
  (:set_service_type
   (&optional __set_service_type)
   (if __set_service_type (setq _set_service_type __set_service_type)) _set_service_type)
  (:interface_type
   (&optional __interface_type)
   (if __interface_type (setq _interface_type __interface_type)) _interface_type)
  (:timestamp
   (&optional __timestamp)
   (if __timestamp (setq _timestamp __timestamp)) _timestamp)
  (:serialization-length
   ()
   (+
    ;; string _interface_name
    4 (length _interface_name)
    ;; string _message_type
    4 (length _message_type)
    ;; string _get_service_name
    4 (length _get_service_name)
    ;; string _get_service_type
    4 (length _get_service_type)
    ;; string _set_service_name
    4 (length _set_service_name)
    ;; string _set_service_type
    4 (length _set_service_type)
    ;; string _interface_type
    4 (length _interface_type)
    ;; time _timestamp
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _interface_name
       (write-long (length _interface_name) s) (princ _interface_name s)
     ;; string _message_type
       (write-long (length _message_type) s) (princ _message_type s)
     ;; string _get_service_name
       (write-long (length _get_service_name) s) (princ _get_service_name s)
     ;; string _get_service_type
       (write-long (length _get_service_type) s) (princ _get_service_type s)
     ;; string _set_service_name
       (write-long (length _set_service_name) s) (princ _set_service_name s)
     ;; string _set_service_type
       (write-long (length _set_service_type) s) (princ _set_service_type s)
     ;; string _interface_type
       (write-long (length _interface_type) s) (princ _interface_type s)
     ;; time _timestamp
       (write-long (send _timestamp :sec) s) (write-long (send _timestamp :nsec) s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _interface_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _interface_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _message_type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message_type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _get_service_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _get_service_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _get_service_type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _get_service_type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _set_service_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _set_service_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _set_service_type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _set_service_type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _interface_type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _interface_type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; time _timestamp
     (send _timestamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _timestamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get lama_msgs::InterfaceInfo :md5sum-) "156de5bd66b7a123b19f5a2142f26e8c")
(setf (get lama_msgs::InterfaceInfo :datatype-) "lama_msgs/InterfaceInfo")
(setf (get lama_msgs::InterfaceInfo :definition-)
      "# Interface name.
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



(provide :lama_msgs/InterfaceInfo "156de5bd66b7a123b19f5a2142f26e8c")


