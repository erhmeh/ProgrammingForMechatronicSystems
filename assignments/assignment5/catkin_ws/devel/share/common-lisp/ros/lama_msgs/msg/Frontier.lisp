; Auto-generated. Do not edit!


(cl:in-package lama_msgs-msg)


;//! \htmlinclude Frontier.msg.html

(cl:defclass <Frontier> (roslisp-msg-protocol:ros-message)
  ((p1
    :reader p1
    :initarg :p1
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (p2
    :reader p2
    :initarg :p2
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (width
    :reader width
    :initarg :width
    :type cl:float
    :initform 0.0)
   (angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass Frontier (<Frontier>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Frontier>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Frontier)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-msg:<Frontier> is deprecated: use lama_msgs-msg:Frontier instead.")))

(cl:ensure-generic-function 'p1-val :lambda-list '(m))
(cl:defmethod p1-val ((m <Frontier>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:p1-val is deprecated.  Use lama_msgs-msg:p1 instead.")
  (p1 m))

(cl:ensure-generic-function 'p2-val :lambda-list '(m))
(cl:defmethod p2-val ((m <Frontier>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:p2-val is deprecated.  Use lama_msgs-msg:p2 instead.")
  (p2 m))

(cl:ensure-generic-function 'width-val :lambda-list '(m))
(cl:defmethod width-val ((m <Frontier>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:width-val is deprecated.  Use lama_msgs-msg:width instead.")
  (width m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <Frontier>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:angle-val is deprecated.  Use lama_msgs-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Frontier>) ostream)
  "Serializes a message object of type '<Frontier>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'p1) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'p2) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'width))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Frontier>) istream)
  "Deserializes a message object of type '<Frontier>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'p1) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'p2) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'width) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Frontier>)))
  "Returns string type for a message object of type '<Frontier>"
  "lama_msgs/Frontier")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Frontier)))
  "Returns string type for a message object of type 'Frontier"
  "lama_msgs/Frontier")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Frontier>)))
  "Returns md5sum for a message object of type '<Frontier>"
  "626f51fb9d901b07427079891bd87ce3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Frontier)))
  "Returns md5sum for a message object of type 'Frontier"
  "626f51fb9d901b07427079891bd87ce3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Frontier>)))
  "Returns full string definition for message of type '<Frontier>"
  (cl:format cl:nil "# Frontier is a line segment through which a robot can go.~%~%# First point~%geometry_msgs/Point p1~%~%# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.~%geometry_msgs/Point p2~%~%# Segment length, i.e. width of free space~%float32 width~%~%# Angle between x-axis and line between origin and frontier middle. Where x-axis~%# and origin refer to the data from which the frontier is computed, in general a LaserScan.~%float32 angle~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Frontier)))
  "Returns full string definition for message of type 'Frontier"
  (cl:format cl:nil "# Frontier is a line segment through which a robot can go.~%~%# First point~%geometry_msgs/Point p1~%~%# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.~%geometry_msgs/Point p2~%~%# Segment length, i.e. width of free space~%float32 width~%~%# Angle between x-axis and line between origin and frontier middle. Where x-axis~%# and origin refer to the data from which the frontier is computed, in general a LaserScan.~%float32 angle~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Frontier>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'p1))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'p2))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Frontier>))
  "Converts a ROS message object to a list"
  (cl:list 'Frontier
    (cl:cons ':p1 (p1 msg))
    (cl:cons ':p2 (p2 msg))
    (cl:cons ':width (width msg))
    (cl:cons ':angle (angle msg))
))
