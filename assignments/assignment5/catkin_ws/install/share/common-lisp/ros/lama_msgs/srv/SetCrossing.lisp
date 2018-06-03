; Auto-generated. Do not edit!


(cl:in-package lama_msgs-srv)


;//! \htmlinclude SetCrossing-request.msg.html

(cl:defclass <SetCrossing-request> (roslisp-msg-protocol:ros-message)
  ((descriptor
    :reader descriptor
    :initarg :descriptor
    :type lama_msgs-msg:Crossing
    :initform (cl:make-instance 'lama_msgs-msg:Crossing)))
)

(cl:defclass SetCrossing-request (<SetCrossing-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetCrossing-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetCrossing-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<SetCrossing-request> is deprecated: use lama_msgs-srv:SetCrossing-request instead.")))

(cl:ensure-generic-function 'descriptor-val :lambda-list '(m))
(cl:defmethod descriptor-val ((m <SetCrossing-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:descriptor-val is deprecated.  Use lama_msgs-srv:descriptor instead.")
  (descriptor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetCrossing-request>) ostream)
  "Serializes a message object of type '<SetCrossing-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'descriptor) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetCrossing-request>) istream)
  "Deserializes a message object of type '<SetCrossing-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'descriptor) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetCrossing-request>)))
  "Returns string type for a service object of type '<SetCrossing-request>"
  "lama_msgs/SetCrossingRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetCrossing-request)))
  "Returns string type for a service object of type 'SetCrossing-request"
  "lama_msgs/SetCrossingRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetCrossing-request>)))
  "Returns md5sum for a message object of type '<SetCrossing-request>"
  "400039bcfb4fed83ffb70a6297f272bc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetCrossing-request)))
  "Returns md5sum for a message object of type 'SetCrossing-request"
  "400039bcfb4fed83ffb70a6297f272bc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetCrossing-request>)))
  "Returns full string definition for message of type '<SetCrossing-request>"
  (cl:format cl:nil "Crossing descriptor~%~%================================================================================~%MSG: lama_msgs/Crossing~%# The main aim of a crossing is to store frontier information.~%~%# Crossing center.~%geometry_msgs/Point center~%~%# Crossing radius.~%float32 radius~%~%# Max. range of the data used to compute the crossing.~%float32 max_range~%~%Frontier[] frontiers~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: lama_msgs/Frontier~%# Frontier is a line segment through which a robot can go.~%~%# First point~%geometry_msgs/Point p1~%~%# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.~%geometry_msgs/Point p2~%~%# Segment length, i.e. width of free space~%float32 width~%~%# Angle between x-axis and line between origin and frontier middle. Where x-axis~%# and origin refer to the data from which the frontier is computed, in general a LaserScan.~%float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetCrossing-request)))
  "Returns full string definition for message of type 'SetCrossing-request"
  (cl:format cl:nil "Crossing descriptor~%~%================================================================================~%MSG: lama_msgs/Crossing~%# The main aim of a crossing is to store frontier information.~%~%# Crossing center.~%geometry_msgs/Point center~%~%# Crossing radius.~%float32 radius~%~%# Max. range of the data used to compute the crossing.~%float32 max_range~%~%Frontier[] frontiers~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: lama_msgs/Frontier~%# Frontier is a line segment through which a robot can go.~%~%# First point~%geometry_msgs/Point p1~%~%# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.~%geometry_msgs/Point p2~%~%# Segment length, i.e. width of free space~%float32 width~%~%# Angle between x-axis and line between origin and frontier middle. Where x-axis~%# and origin refer to the data from which the frontier is computed, in general a LaserScan.~%float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetCrossing-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'descriptor))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetCrossing-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetCrossing-request
    (cl:cons ':descriptor (descriptor msg))
))
;//! \htmlinclude SetCrossing-response.msg.html

(cl:defclass <SetCrossing-response> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0))
)

(cl:defclass SetCrossing-response (<SetCrossing-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetCrossing-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetCrossing-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<SetCrossing-response> is deprecated: use lama_msgs-srv:SetCrossing-response instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <SetCrossing-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:id-val is deprecated.  Use lama_msgs-srv:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetCrossing-response>) ostream)
  "Serializes a message object of type '<SetCrossing-response>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetCrossing-response>) istream)
  "Deserializes a message object of type '<SetCrossing-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetCrossing-response>)))
  "Returns string type for a service object of type '<SetCrossing-response>"
  "lama_msgs/SetCrossingResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetCrossing-response)))
  "Returns string type for a service object of type 'SetCrossing-response"
  "lama_msgs/SetCrossingResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetCrossing-response>)))
  "Returns md5sum for a message object of type '<SetCrossing-response>"
  "400039bcfb4fed83ffb70a6297f272bc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetCrossing-response)))
  "Returns md5sum for a message object of type 'SetCrossing-response"
  "400039bcfb4fed83ffb70a6297f272bc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetCrossing-response>)))
  "Returns full string definition for message of type '<SetCrossing-response>"
  (cl:format cl:nil "int32 id~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetCrossing-response)))
  "Returns full string definition for message of type 'SetCrossing-response"
  (cl:format cl:nil "int32 id~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetCrossing-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetCrossing-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetCrossing-response
    (cl:cons ':id (id msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetCrossing)))
  'SetCrossing-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetCrossing)))
  'SetCrossing-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetCrossing)))
  "Returns string type for a service object of type '<SetCrossing>"
  "lama_msgs/SetCrossing")