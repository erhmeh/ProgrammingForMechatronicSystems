; Auto-generated. Do not edit!


(cl:in-package lama_msgs-msg)


;//! \htmlinclude LamaObject.msg.html

(cl:defclass <LamaObject> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (id_in_world
    :reader id_in_world
    :initarg :id_in_world
    :type cl:integer
    :initform 0)
   (name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (emitter_id
    :reader emitter_id
    :initarg :emitter_id
    :type cl:integer
    :initform 0)
   (emitter_name
    :reader emitter_name
    :initarg :emitter_name
    :type cl:string
    :initform "")
   (type
    :reader type
    :initarg :type
    :type cl:integer
    :initform 0)
   (references
    :reader references
    :initarg :references
    :type (cl:vector cl:integer)
   :initform (cl:make-array 2 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass LamaObject (<LamaObject>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LamaObject>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LamaObject)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-msg:<LamaObject> is deprecated: use lama_msgs-msg:LamaObject instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <LamaObject>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:id-val is deprecated.  Use lama_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'id_in_world-val :lambda-list '(m))
(cl:defmethod id_in_world-val ((m <LamaObject>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:id_in_world-val is deprecated.  Use lama_msgs-msg:id_in_world instead.")
  (id_in_world m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <LamaObject>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:name-val is deprecated.  Use lama_msgs-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'emitter_id-val :lambda-list '(m))
(cl:defmethod emitter_id-val ((m <LamaObject>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:emitter_id-val is deprecated.  Use lama_msgs-msg:emitter_id instead.")
  (emitter_id m))

(cl:ensure-generic-function 'emitter_name-val :lambda-list '(m))
(cl:defmethod emitter_name-val ((m <LamaObject>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:emitter_name-val is deprecated.  Use lama_msgs-msg:emitter_name instead.")
  (emitter_name m))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <LamaObject>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:type-val is deprecated.  Use lama_msgs-msg:type instead.")
  (type m))

(cl:ensure-generic-function 'references-val :lambda-list '(m))
(cl:defmethod references-val ((m <LamaObject>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:references-val is deprecated.  Use lama_msgs-msg:references instead.")
  (references m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<LamaObject>)))
    "Constants for message type '<LamaObject>"
  '((:VERTEX . 1)
    (:EDGE . 2))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'LamaObject)))
    "Constants for message type 'LamaObject"
  '((:VERTEX . 1)
    (:EDGE . 2))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LamaObject>) ostream)
  "Serializes a message object of type '<LamaObject>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'id_in_world)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let* ((signed (cl:slot-value msg 'emitter_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'emitter_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'emitter_name))
  (cl:let* ((signed (cl:slot-value msg 'type)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'references))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LamaObject>) istream)
  "Deserializes a message object of type '<LamaObject>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id_in_world) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'emitter_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'emitter_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'emitter_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'type) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:setf (cl:slot-value msg 'references) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'references)))
    (cl:dotimes (i 2)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LamaObject>)))
  "Returns string type for a message object of type '<LamaObject>"
  "lama_msgs/LamaObject")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LamaObject)))
  "Returns string type for a message object of type 'LamaObject"
  "lama_msgs/LamaObject")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LamaObject>)))
  "Returns md5sum for a message object of type '<LamaObject>"
  "e2747a1741c10b06140b9673d9018102")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LamaObject)))
  "Returns md5sum for a message object of type 'LamaObject"
  "e2747a1741c10b06140b9673d9018102")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LamaObject>)))
  "Returns full string definition for message of type '<LamaObject>"
  (cl:format cl:nil "# id of lama object in the database, will be unique.~%# When adding a vertex into the database, this id will be ignored.~%int32 id~%~%# id of lama object in the world (usage is implementation specific).~%int32 id_in_world~%~%# name of object~%string name~%~%# emitter id and name.~%int32 emitter_id~%string emitter_name~%~%# type: \"EDGE\" or \"VERTEX\"~%int32 type~%int32 VERTEX = 1~%int32 EDGE = 2~%~%# for edges: start and end vertices~%# for vertices: not used~%int32[2] references~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LamaObject)))
  "Returns full string definition for message of type 'LamaObject"
  (cl:format cl:nil "# id of lama object in the database, will be unique.~%# When adding a vertex into the database, this id will be ignored.~%int32 id~%~%# id of lama object in the world (usage is implementation specific).~%int32 id_in_world~%~%# name of object~%string name~%~%# emitter id and name.~%int32 emitter_id~%string emitter_name~%~%# type: \"EDGE\" or \"VERTEX\"~%int32 type~%int32 VERTEX = 1~%int32 EDGE = 2~%~%# for edges: start and end vertices~%# for vertices: not used~%int32[2] references~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LamaObject>))
  (cl:+ 0
     4
     4
     4 (cl:length (cl:slot-value msg 'name))
     4
     4 (cl:length (cl:slot-value msg 'emitter_name))
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'references) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LamaObject>))
  "Converts a ROS message object to a list"
  (cl:list 'LamaObject
    (cl:cons ':id (id msg))
    (cl:cons ':id_in_world (id_in_world msg))
    (cl:cons ':name (name msg))
    (cl:cons ':emitter_id (emitter_id msg))
    (cl:cons ':emitter_name (emitter_name msg))
    (cl:cons ':type (type msg))
    (cl:cons ':references (references msg))
))
