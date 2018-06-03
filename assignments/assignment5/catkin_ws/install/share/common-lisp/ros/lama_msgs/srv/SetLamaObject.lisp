; Auto-generated. Do not edit!


(cl:in-package lama_msgs-srv)


;//! \htmlinclude SetLamaObject-request.msg.html

(cl:defclass <SetLamaObject-request> (roslisp-msg-protocol:ros-message)
  ((object
    :reader object
    :initarg :object
    :type lama_msgs-msg:LamaObject
    :initform (cl:make-instance 'lama_msgs-msg:LamaObject)))
)

(cl:defclass SetLamaObject-request (<SetLamaObject-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetLamaObject-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetLamaObject-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<SetLamaObject-request> is deprecated: use lama_msgs-srv:SetLamaObject-request instead.")))

(cl:ensure-generic-function 'object-val :lambda-list '(m))
(cl:defmethod object-val ((m <SetLamaObject-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:object-val is deprecated.  Use lama_msgs-srv:object instead.")
  (object m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetLamaObject-request>) ostream)
  "Serializes a message object of type '<SetLamaObject-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'object) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetLamaObject-request>) istream)
  "Deserializes a message object of type '<SetLamaObject-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'object) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetLamaObject-request>)))
  "Returns string type for a service object of type '<SetLamaObject-request>"
  "lama_msgs/SetLamaObjectRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetLamaObject-request)))
  "Returns string type for a service object of type 'SetLamaObject-request"
  "lama_msgs/SetLamaObjectRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetLamaObject-request>)))
  "Returns md5sum for a message object of type '<SetLamaObject-request>"
  "f191a122fd81f40804a5436e7a94b04c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetLamaObject-request)))
  "Returns md5sum for a message object of type 'SetLamaObject-request"
  "f191a122fd81f40804a5436e7a94b04c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetLamaObject-request>)))
  "Returns full string definition for message of type '<SetLamaObject-request>"
  (cl:format cl:nil "LamaObject object~%~%================================================================================~%MSG: lama_msgs/LamaObject~%# id of lama object in the database, will be unique.~%# When adding a vertex into the database, this id will be ignored.~%int32 id~%~%# id of lama object in the world (usage is implementation specific).~%int32 id_in_world~%~%# name of object~%string name~%~%# emitter id and name.~%int32 emitter_id~%string emitter_name~%~%# type: \"EDGE\" or \"VERTEX\"~%int32 type~%int32 VERTEX = 1~%int32 EDGE = 2~%~%# for edges: start and end vertices~%# for vertices: not used~%int32[2] references~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetLamaObject-request)))
  "Returns full string definition for message of type 'SetLamaObject-request"
  (cl:format cl:nil "LamaObject object~%~%================================================================================~%MSG: lama_msgs/LamaObject~%# id of lama object in the database, will be unique.~%# When adding a vertex into the database, this id will be ignored.~%int32 id~%~%# id of lama object in the world (usage is implementation specific).~%int32 id_in_world~%~%# name of object~%string name~%~%# emitter id and name.~%int32 emitter_id~%string emitter_name~%~%# type: \"EDGE\" or \"VERTEX\"~%int32 type~%int32 VERTEX = 1~%int32 EDGE = 2~%~%# for edges: start and end vertices~%# for vertices: not used~%int32[2] references~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetLamaObject-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'object))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetLamaObject-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetLamaObject-request
    (cl:cons ':object (object msg))
))
;//! \htmlinclude SetLamaObject-response.msg.html

(cl:defclass <SetLamaObject-response> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0))
)

(cl:defclass SetLamaObject-response (<SetLamaObject-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetLamaObject-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetLamaObject-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<SetLamaObject-response> is deprecated: use lama_msgs-srv:SetLamaObject-response instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <SetLamaObject-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:id-val is deprecated.  Use lama_msgs-srv:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetLamaObject-response>) ostream)
  "Serializes a message object of type '<SetLamaObject-response>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetLamaObject-response>) istream)
  "Deserializes a message object of type '<SetLamaObject-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetLamaObject-response>)))
  "Returns string type for a service object of type '<SetLamaObject-response>"
  "lama_msgs/SetLamaObjectResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetLamaObject-response)))
  "Returns string type for a service object of type 'SetLamaObject-response"
  "lama_msgs/SetLamaObjectResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetLamaObject-response>)))
  "Returns md5sum for a message object of type '<SetLamaObject-response>"
  "f191a122fd81f40804a5436e7a94b04c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetLamaObject-response)))
  "Returns md5sum for a message object of type 'SetLamaObject-response"
  "f191a122fd81f40804a5436e7a94b04c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetLamaObject-response>)))
  "Returns full string definition for message of type '<SetLamaObject-response>"
  (cl:format cl:nil "int32 id~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetLamaObject-response)))
  "Returns full string definition for message of type 'SetLamaObject-response"
  (cl:format cl:nil "int32 id~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetLamaObject-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetLamaObject-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetLamaObject-response
    (cl:cons ':id (id msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetLamaObject)))
  'SetLamaObject-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetLamaObject)))
  'SetLamaObject-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetLamaObject)))
  "Returns string type for a service object of type '<SetLamaObject>"
  "lama_msgs/SetLamaObject")