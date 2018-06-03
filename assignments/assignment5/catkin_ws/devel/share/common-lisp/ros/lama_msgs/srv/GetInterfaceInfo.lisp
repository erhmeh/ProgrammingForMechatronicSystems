; Auto-generated. Do not edit!


(cl:in-package lama_msgs-srv)


;//! \htmlinclude GetInterfaceInfo-request.msg.html

(cl:defclass <GetInterfaceInfo-request> (roslisp-msg-protocol:ros-message)
  ((interface_name
    :reader interface_name
    :initarg :interface_name
    :type cl:string
    :initform ""))
)

(cl:defclass GetInterfaceInfo-request (<GetInterfaceInfo-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetInterfaceInfo-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetInterfaceInfo-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<GetInterfaceInfo-request> is deprecated: use lama_msgs-srv:GetInterfaceInfo-request instead.")))

(cl:ensure-generic-function 'interface_name-val :lambda-list '(m))
(cl:defmethod interface_name-val ((m <GetInterfaceInfo-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:interface_name-val is deprecated.  Use lama_msgs-srv:interface_name instead.")
  (interface_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetInterfaceInfo-request>) ostream)
  "Serializes a message object of type '<GetInterfaceInfo-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'interface_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'interface_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetInterfaceInfo-request>) istream)
  "Deserializes a message object of type '<GetInterfaceInfo-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'interface_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'interface_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetInterfaceInfo-request>)))
  "Returns string type for a service object of type '<GetInterfaceInfo-request>"
  "lama_msgs/GetInterfaceInfoRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetInterfaceInfo-request)))
  "Returns string type for a service object of type 'GetInterfaceInfo-request"
  "lama_msgs/GetInterfaceInfoRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetInterfaceInfo-request>)))
  "Returns md5sum for a message object of type '<GetInterfaceInfo-request>"
  "88018d5bbc756bb20b9d16e277b1cdc7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetInterfaceInfo-request)))
  "Returns md5sum for a message object of type 'GetInterfaceInfo-request"
  "88018d5bbc756bb20b9d16e277b1cdc7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetInterfaceInfo-request>)))
  "Returns full string definition for message of type '<GetInterfaceInfo-request>"
  (cl:format cl:nil "~%string interface_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetInterfaceInfo-request)))
  "Returns full string definition for message of type 'GetInterfaceInfo-request"
  (cl:format cl:nil "~%string interface_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetInterfaceInfo-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'interface_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetInterfaceInfo-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetInterfaceInfo-request
    (cl:cons ':interface_name (interface_name msg))
))
;//! \htmlinclude GetInterfaceInfo-response.msg.html

(cl:defclass <GetInterfaceInfo-response> (roslisp-msg-protocol:ros-message)
  ((interface_info
    :reader interface_info
    :initarg :interface_info
    :type lama_msgs-msg:InterfaceInfo
    :initform (cl:make-instance 'lama_msgs-msg:InterfaceInfo)))
)

(cl:defclass GetInterfaceInfo-response (<GetInterfaceInfo-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetInterfaceInfo-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetInterfaceInfo-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<GetInterfaceInfo-response> is deprecated: use lama_msgs-srv:GetInterfaceInfo-response instead.")))

(cl:ensure-generic-function 'interface_info-val :lambda-list '(m))
(cl:defmethod interface_info-val ((m <GetInterfaceInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:interface_info-val is deprecated.  Use lama_msgs-srv:interface_info instead.")
  (interface_info m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetInterfaceInfo-response>) ostream)
  "Serializes a message object of type '<GetInterfaceInfo-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'interface_info) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetInterfaceInfo-response>) istream)
  "Deserializes a message object of type '<GetInterfaceInfo-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'interface_info) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetInterfaceInfo-response>)))
  "Returns string type for a service object of type '<GetInterfaceInfo-response>"
  "lama_msgs/GetInterfaceInfoResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetInterfaceInfo-response)))
  "Returns string type for a service object of type 'GetInterfaceInfo-response"
  "lama_msgs/GetInterfaceInfoResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetInterfaceInfo-response>)))
  "Returns md5sum for a message object of type '<GetInterfaceInfo-response>"
  "88018d5bbc756bb20b9d16e277b1cdc7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetInterfaceInfo-response)))
  "Returns md5sum for a message object of type 'GetInterfaceInfo-response"
  "88018d5bbc756bb20b9d16e277b1cdc7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetInterfaceInfo-response>)))
  "Returns full string definition for message of type '<GetInterfaceInfo-response>"
  (cl:format cl:nil "InterfaceInfo interface_info~%~%~%================================================================================~%MSG: lama_msgs/InterfaceInfo~%# Interface name.~%string interface_name~%~%# The type of message associated with the interface.~%string message_type~%~%# The name of the associated service for getting a message.~%string get_service_name~%~%# The service message of the service for getting a message.~%string get_service_type~%~%# The name of the associated service for setting a message.~%string set_service_name~%~%# The service message of the service for setting a message.~%string set_service_type~%~%string interface_type~%~%# Timestamp of the last added message through this interface.~%time timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetInterfaceInfo-response)))
  "Returns full string definition for message of type 'GetInterfaceInfo-response"
  (cl:format cl:nil "InterfaceInfo interface_info~%~%~%================================================================================~%MSG: lama_msgs/InterfaceInfo~%# Interface name.~%string interface_name~%~%# The type of message associated with the interface.~%string message_type~%~%# The name of the associated service for getting a message.~%string get_service_name~%~%# The service message of the service for getting a message.~%string get_service_type~%~%# The name of the associated service for setting a message.~%string set_service_name~%~%# The service message of the service for setting a message.~%string set_service_type~%~%string interface_type~%~%# Timestamp of the last added message through this interface.~%time timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetInterfaceInfo-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'interface_info))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetInterfaceInfo-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetInterfaceInfo-response
    (cl:cons ':interface_info (interface_info msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetInterfaceInfo)))
  'GetInterfaceInfo-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetInterfaceInfo)))
  'GetInterfaceInfo-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetInterfaceInfo)))
  "Returns string type for a service object of type '<GetInterfaceInfo>"
  "lama_msgs/GetInterfaceInfo")