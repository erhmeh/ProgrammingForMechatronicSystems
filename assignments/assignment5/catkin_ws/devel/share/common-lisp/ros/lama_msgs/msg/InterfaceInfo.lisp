; Auto-generated. Do not edit!


(cl:in-package lama_msgs-msg)


;//! \htmlinclude InterfaceInfo.msg.html

(cl:defclass <InterfaceInfo> (roslisp-msg-protocol:ros-message)
  ((interface_name
    :reader interface_name
    :initarg :interface_name
    :type cl:string
    :initform "")
   (message_type
    :reader message_type
    :initarg :message_type
    :type cl:string
    :initform "")
   (get_service_name
    :reader get_service_name
    :initarg :get_service_name
    :type cl:string
    :initform "")
   (get_service_type
    :reader get_service_type
    :initarg :get_service_type
    :type cl:string
    :initform "")
   (set_service_name
    :reader set_service_name
    :initarg :set_service_name
    :type cl:string
    :initform "")
   (set_service_type
    :reader set_service_type
    :initarg :set_service_type
    :type cl:string
    :initform "")
   (interface_type
    :reader interface_type
    :initarg :interface_type
    :type cl:string
    :initform "")
   (timestamp
    :reader timestamp
    :initarg :timestamp
    :type cl:real
    :initform 0))
)

(cl:defclass InterfaceInfo (<InterfaceInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <InterfaceInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'InterfaceInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-msg:<InterfaceInfo> is deprecated: use lama_msgs-msg:InterfaceInfo instead.")))

(cl:ensure-generic-function 'interface_name-val :lambda-list '(m))
(cl:defmethod interface_name-val ((m <InterfaceInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:interface_name-val is deprecated.  Use lama_msgs-msg:interface_name instead.")
  (interface_name m))

(cl:ensure-generic-function 'message_type-val :lambda-list '(m))
(cl:defmethod message_type-val ((m <InterfaceInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:message_type-val is deprecated.  Use lama_msgs-msg:message_type instead.")
  (message_type m))

(cl:ensure-generic-function 'get_service_name-val :lambda-list '(m))
(cl:defmethod get_service_name-val ((m <InterfaceInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:get_service_name-val is deprecated.  Use lama_msgs-msg:get_service_name instead.")
  (get_service_name m))

(cl:ensure-generic-function 'get_service_type-val :lambda-list '(m))
(cl:defmethod get_service_type-val ((m <InterfaceInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:get_service_type-val is deprecated.  Use lama_msgs-msg:get_service_type instead.")
  (get_service_type m))

(cl:ensure-generic-function 'set_service_name-val :lambda-list '(m))
(cl:defmethod set_service_name-val ((m <InterfaceInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:set_service_name-val is deprecated.  Use lama_msgs-msg:set_service_name instead.")
  (set_service_name m))

(cl:ensure-generic-function 'set_service_type-val :lambda-list '(m))
(cl:defmethod set_service_type-val ((m <InterfaceInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:set_service_type-val is deprecated.  Use lama_msgs-msg:set_service_type instead.")
  (set_service_type m))

(cl:ensure-generic-function 'interface_type-val :lambda-list '(m))
(cl:defmethod interface_type-val ((m <InterfaceInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:interface_type-val is deprecated.  Use lama_msgs-msg:interface_type instead.")
  (interface_type m))

(cl:ensure-generic-function 'timestamp-val :lambda-list '(m))
(cl:defmethod timestamp-val ((m <InterfaceInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:timestamp-val is deprecated.  Use lama_msgs-msg:timestamp instead.")
  (timestamp m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <InterfaceInfo>) ostream)
  "Serializes a message object of type '<InterfaceInfo>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'interface_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'interface_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message_type))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'get_service_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'get_service_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'get_service_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'get_service_type))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'set_service_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'set_service_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'set_service_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'set_service_type))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'interface_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'interface_type))
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'timestamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'timestamp) (cl:floor (cl:slot-value msg 'timestamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <InterfaceInfo>) istream)
  "Deserializes a message object of type '<InterfaceInfo>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'interface_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'interface_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'get_service_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'get_service_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'get_service_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'get_service_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'set_service_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'set_service_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'set_service_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'set_service_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'interface_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'interface_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'timestamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<InterfaceInfo>)))
  "Returns string type for a message object of type '<InterfaceInfo>"
  "lama_msgs/InterfaceInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'InterfaceInfo)))
  "Returns string type for a message object of type 'InterfaceInfo"
  "lama_msgs/InterfaceInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<InterfaceInfo>)))
  "Returns md5sum for a message object of type '<InterfaceInfo>"
  "156de5bd66b7a123b19f5a2142f26e8c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'InterfaceInfo)))
  "Returns md5sum for a message object of type 'InterfaceInfo"
  "156de5bd66b7a123b19f5a2142f26e8c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<InterfaceInfo>)))
  "Returns full string definition for message of type '<InterfaceInfo>"
  (cl:format cl:nil "# Interface name.~%string interface_name~%~%# The type of message associated with the interface.~%string message_type~%~%# The name of the associated service for getting a message.~%string get_service_name~%~%# The service message of the service for getting a message.~%string get_service_type~%~%# The name of the associated service for setting a message.~%string set_service_name~%~%# The service message of the service for setting a message.~%string set_service_type~%~%string interface_type~%~%# Timestamp of the last added message through this interface.~%time timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'InterfaceInfo)))
  "Returns full string definition for message of type 'InterfaceInfo"
  (cl:format cl:nil "# Interface name.~%string interface_name~%~%# The type of message associated with the interface.~%string message_type~%~%# The name of the associated service for getting a message.~%string get_service_name~%~%# The service message of the service for getting a message.~%string get_service_type~%~%# The name of the associated service for setting a message.~%string set_service_name~%~%# The service message of the service for setting a message.~%string set_service_type~%~%string interface_type~%~%# Timestamp of the last added message through this interface.~%time timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <InterfaceInfo>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'interface_name))
     4 (cl:length (cl:slot-value msg 'message_type))
     4 (cl:length (cl:slot-value msg 'get_service_name))
     4 (cl:length (cl:slot-value msg 'get_service_type))
     4 (cl:length (cl:slot-value msg 'set_service_name))
     4 (cl:length (cl:slot-value msg 'set_service_type))
     4 (cl:length (cl:slot-value msg 'interface_type))
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <InterfaceInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'InterfaceInfo
    (cl:cons ':interface_name (interface_name msg))
    (cl:cons ':message_type (message_type msg))
    (cl:cons ':get_service_name (get_service_name msg))
    (cl:cons ':get_service_type (get_service_type msg))
    (cl:cons ':set_service_name (set_service_name msg))
    (cl:cons ':set_service_type (set_service_type msg))
    (cl:cons ':interface_type (interface_type msg))
    (cl:cons ':timestamp (timestamp msg))
))
