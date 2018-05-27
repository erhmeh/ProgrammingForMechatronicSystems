; Auto-generated. Do not edit!


(cl:in-package lama_msgs-msg)


;//! \htmlinclude DescriptorLink.msg.html

(cl:defclass <DescriptorLink> (roslisp-msg-protocol:ros-message)
  ((object_id
    :reader object_id
    :initarg :object_id
    :type cl:integer
    :initform 0)
   (descriptor_id
    :reader descriptor_id
    :initarg :descriptor_id
    :type cl:integer
    :initform 0)
   (interface_name
    :reader interface_name
    :initarg :interface_name
    :type cl:string
    :initform ""))
)

(cl:defclass DescriptorLink (<DescriptorLink>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DescriptorLink>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DescriptorLink)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-msg:<DescriptorLink> is deprecated: use lama_msgs-msg:DescriptorLink instead.")))

(cl:ensure-generic-function 'object_id-val :lambda-list '(m))
(cl:defmethod object_id-val ((m <DescriptorLink>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:object_id-val is deprecated.  Use lama_msgs-msg:object_id instead.")
  (object_id m))

(cl:ensure-generic-function 'descriptor_id-val :lambda-list '(m))
(cl:defmethod descriptor_id-val ((m <DescriptorLink>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:descriptor_id-val is deprecated.  Use lama_msgs-msg:descriptor_id instead.")
  (descriptor_id m))

(cl:ensure-generic-function 'interface_name-val :lambda-list '(m))
(cl:defmethod interface_name-val ((m <DescriptorLink>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:interface_name-val is deprecated.  Use lama_msgs-msg:interface_name instead.")
  (interface_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DescriptorLink>) ostream)
  "Serializes a message object of type '<DescriptorLink>"
  (cl:let* ((signed (cl:slot-value msg 'object_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'descriptor_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'interface_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'interface_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DescriptorLink>) istream)
  "Deserializes a message object of type '<DescriptorLink>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'object_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'descriptor_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DescriptorLink>)))
  "Returns string type for a message object of type '<DescriptorLink>"
  "lama_msgs/DescriptorLink")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DescriptorLink)))
  "Returns string type for a message object of type 'DescriptorLink"
  "lama_msgs/DescriptorLink")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DescriptorLink>)))
  "Returns md5sum for a message object of type '<DescriptorLink>"
  "7f6d6af0c2f5ed48be6d42a3bb530828")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DescriptorLink)))
  "Returns md5sum for a message object of type 'DescriptorLink"
  "7f6d6af0c2f5ed48be6d42a3bb530828")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DescriptorLink>)))
  "Returns full string definition for message of type '<DescriptorLink>"
  (cl:format cl:nil "# A DescriptorLink is a bond between a Lama object and a descriptor.~%~%# Id of the Lama object associated with the descriptor (in the database).~%int32 object_id~%~%# Id of the associated descriptor (in the database).~%int32 descriptor_id ~%~%# Interface name which also identifies the descriptor type.~%string interface_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DescriptorLink)))
  "Returns full string definition for message of type 'DescriptorLink"
  (cl:format cl:nil "# A DescriptorLink is a bond between a Lama object and a descriptor.~%~%# Id of the Lama object associated with the descriptor (in the database).~%int32 object_id~%~%# Id of the associated descriptor (in the database).~%int32 descriptor_id ~%~%# Interface name which also identifies the descriptor type.~%string interface_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DescriptorLink>))
  (cl:+ 0
     4
     4
     4 (cl:length (cl:slot-value msg 'interface_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DescriptorLink>))
  "Converts a ROS message object to a list"
  (cl:list 'DescriptorLink
    (cl:cons ':object_id (object_id msg))
    (cl:cons ':descriptor_id (descriptor_id msg))
    (cl:cons ':interface_name (interface_name msg))
))
