; Auto-generated. Do not edit!


(cl:in-package lama_msgs-srv)


;//! \htmlinclude GetCrossing-request.msg.html

(cl:defclass <GetCrossing-request> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0))
)

(cl:defclass GetCrossing-request (<GetCrossing-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetCrossing-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetCrossing-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<GetCrossing-request> is deprecated: use lama_msgs-srv:GetCrossing-request instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <GetCrossing-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:id-val is deprecated.  Use lama_msgs-srv:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetCrossing-request>) ostream)
  "Serializes a message object of type '<GetCrossing-request>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetCrossing-request>) istream)
  "Deserializes a message object of type '<GetCrossing-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetCrossing-request>)))
  "Returns string type for a service object of type '<GetCrossing-request>"
  "lama_msgs/GetCrossingRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetCrossing-request)))
  "Returns string type for a service object of type 'GetCrossing-request"
  "lama_msgs/GetCrossingRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetCrossing-request>)))
  "Returns md5sum for a message object of type '<GetCrossing-request>"
  "4842af2f1edf5a2e9caf0cee19515bcc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetCrossing-request)))
  "Returns md5sum for a message object of type 'GetCrossing-request"
  "4842af2f1edf5a2e9caf0cee19515bcc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetCrossing-request>)))
  "Returns full string definition for message of type '<GetCrossing-request>"
  (cl:format cl:nil "int32 id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetCrossing-request)))
  "Returns full string definition for message of type 'GetCrossing-request"
  (cl:format cl:nil "int32 id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetCrossing-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetCrossing-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetCrossing-request
    (cl:cons ':id (id msg))
))
;//! \htmlinclude GetCrossing-response.msg.html

(cl:defclass <GetCrossing-response> (roslisp-msg-protocol:ros-message)
  ((descriptor
    :reader descriptor
    :initarg :descriptor
    :type lama_msgs-msg:Crossing
    :initform (cl:make-instance 'lama_msgs-msg:Crossing)))
)

(cl:defclass GetCrossing-response (<GetCrossing-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetCrossing-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetCrossing-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<GetCrossing-response> is deprecated: use lama_msgs-srv:GetCrossing-response instead.")))

(cl:ensure-generic-function 'descriptor-val :lambda-list '(m))
(cl:defmethod descriptor-val ((m <GetCrossing-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:descriptor-val is deprecated.  Use lama_msgs-srv:descriptor instead.")
  (descriptor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetCrossing-response>) ostream)
  "Serializes a message object of type '<GetCrossing-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'descriptor) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetCrossing-response>) istream)
  "Deserializes a message object of type '<GetCrossing-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'descriptor) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetCrossing-response>)))
  "Returns string type for a service object of type '<GetCrossing-response>"
  "lama_msgs/GetCrossingResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetCrossing-response)))
  "Returns string type for a service object of type 'GetCrossing-response"
  "lama_msgs/GetCrossingResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetCrossing-response>)))
  "Returns md5sum for a message object of type '<GetCrossing-response>"
  "4842af2f1edf5a2e9caf0cee19515bcc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetCrossing-response)))
  "Returns md5sum for a message object of type 'GetCrossing-response"
  "4842af2f1edf5a2e9caf0cee19515bcc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetCrossing-response>)))
  "Returns full string definition for message of type '<GetCrossing-response>"
  (cl:format cl:nil "Crossing descriptor~%~%~%================================================================================~%MSG: lama_msgs/Crossing~%# The main aim of a crossing is to store frontier information.~%~%# Crossing center.~%geometry_msgs/Point center~%~%# Crossing radius.~%float32 radius~%~%# Max. range of the data used to compute the crossing.~%float32 max_range~%~%Frontier[] frontiers~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: lama_msgs/Frontier~%# Frontier is a line segment through which a robot can go.~%~%# First point~%geometry_msgs/Point p1~%~%# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.~%geometry_msgs/Point p2~%~%# Segment length, i.e. width of free space~%float32 width~%~%# Angle between x-axis and line between origin and frontier middle. Where x-axis~%# and origin refer to the data from which the frontier is computed, in general a LaserScan.~%float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetCrossing-response)))
  "Returns full string definition for message of type 'GetCrossing-response"
  (cl:format cl:nil "Crossing descriptor~%~%~%================================================================================~%MSG: lama_msgs/Crossing~%# The main aim of a crossing is to store frontier information.~%~%# Crossing center.~%geometry_msgs/Point center~%~%# Crossing radius.~%float32 radius~%~%# Max. range of the data used to compute the crossing.~%float32 max_range~%~%Frontier[] frontiers~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: lama_msgs/Frontier~%# Frontier is a line segment through which a robot can go.~%~%# First point~%geometry_msgs/Point p1~%~%# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.~%geometry_msgs/Point p2~%~%# Segment length, i.e. width of free space~%float32 width~%~%# Angle between x-axis and line between origin and frontier middle. Where x-axis~%# and origin refer to the data from which the frontier is computed, in general a LaserScan.~%float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetCrossing-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'descriptor))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetCrossing-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetCrossing-response
    (cl:cons ':descriptor (descriptor msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetCrossing)))
  'GetCrossing-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetCrossing)))
  'GetCrossing-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetCrossing)))
  "Returns string type for a service object of type '<GetCrossing>"
  "lama_msgs/GetCrossing")