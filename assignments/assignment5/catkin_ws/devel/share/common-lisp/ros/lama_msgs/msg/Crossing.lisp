; Auto-generated. Do not edit!


(cl:in-package lama_msgs-msg)


;//! \htmlinclude Crossing.msg.html

(cl:defclass <Crossing> (roslisp-msg-protocol:ros-message)
  ((center
    :reader center
    :initarg :center
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (radius
    :reader radius
    :initarg :radius
    :type cl:float
    :initform 0.0)
   (max_range
    :reader max_range
    :initarg :max_range
    :type cl:float
    :initform 0.0)
   (frontiers
    :reader frontiers
    :initarg :frontiers
    :type (cl:vector lama_msgs-msg:Frontier)
   :initform (cl:make-array 0 :element-type 'lama_msgs-msg:Frontier :initial-element (cl:make-instance 'lama_msgs-msg:Frontier))))
)

(cl:defclass Crossing (<Crossing>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Crossing>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Crossing)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-msg:<Crossing> is deprecated: use lama_msgs-msg:Crossing instead.")))

(cl:ensure-generic-function 'center-val :lambda-list '(m))
(cl:defmethod center-val ((m <Crossing>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:center-val is deprecated.  Use lama_msgs-msg:center instead.")
  (center m))

(cl:ensure-generic-function 'radius-val :lambda-list '(m))
(cl:defmethod radius-val ((m <Crossing>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:radius-val is deprecated.  Use lama_msgs-msg:radius instead.")
  (radius m))

(cl:ensure-generic-function 'max_range-val :lambda-list '(m))
(cl:defmethod max_range-val ((m <Crossing>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:max_range-val is deprecated.  Use lama_msgs-msg:max_range instead.")
  (max_range m))

(cl:ensure-generic-function 'frontiers-val :lambda-list '(m))
(cl:defmethod frontiers-val ((m <Crossing>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:frontiers-val is deprecated.  Use lama_msgs-msg:frontiers instead.")
  (frontiers m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Crossing>) ostream)
  "Serializes a message object of type '<Crossing>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'center) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'radius))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'max_range))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'frontiers))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'frontiers))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Crossing>) istream)
  "Deserializes a message object of type '<Crossing>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'center) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radius) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'max_range) (roslisp-utils:decode-single-float-bits bits)))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'frontiers) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'frontiers)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'lama_msgs-msg:Frontier))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Crossing>)))
  "Returns string type for a message object of type '<Crossing>"
  "lama_msgs/Crossing")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Crossing)))
  "Returns string type for a message object of type 'Crossing"
  "lama_msgs/Crossing")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Crossing>)))
  "Returns md5sum for a message object of type '<Crossing>"
  "67addd09c3278311b7859a9f2670cdb2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Crossing)))
  "Returns md5sum for a message object of type 'Crossing"
  "67addd09c3278311b7859a9f2670cdb2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Crossing>)))
  "Returns full string definition for message of type '<Crossing>"
  (cl:format cl:nil "# The main aim of a crossing is to store frontier information.~%~%# Crossing center.~%geometry_msgs/Point center~%~%# Crossing radius.~%float32 radius~%~%# Max. range of the data used to compute the crossing.~%float32 max_range~%~%Frontier[] frontiers~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: lama_msgs/Frontier~%# Frontier is a line segment through which a robot can go.~%~%# First point~%geometry_msgs/Point p1~%~%# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.~%geometry_msgs/Point p2~%~%# Segment length, i.e. width of free space~%float32 width~%~%# Angle between x-axis and line between origin and frontier middle. Where x-axis~%# and origin refer to the data from which the frontier is computed, in general a LaserScan.~%float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Crossing)))
  "Returns full string definition for message of type 'Crossing"
  (cl:format cl:nil "# The main aim of a crossing is to store frontier information.~%~%# Crossing center.~%geometry_msgs/Point center~%~%# Crossing radius.~%float32 radius~%~%# Max. range of the data used to compute the crossing.~%float32 max_range~%~%Frontier[] frontiers~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: lama_msgs/Frontier~%# Frontier is a line segment through which a robot can go.~%~%# First point~%geometry_msgs/Point p1~%~%# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.~%geometry_msgs/Point p2~%~%# Segment length, i.e. width of free space~%float32 width~%~%# Angle between x-axis and line between origin and frontier middle. Where x-axis~%# and origin refer to the data from which the frontier is computed, in general a LaserScan.~%float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Crossing>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'center))
     4
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'frontiers) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Crossing>))
  "Converts a ROS message object to a list"
  (cl:list 'Crossing
    (cl:cons ':center (center msg))
    (cl:cons ':radius (radius msg))
    (cl:cons ':max_range (max_range msg))
    (cl:cons ':frontiers (frontiers msg))
))
