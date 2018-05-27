; Auto-generated. Do not edit!


(cl:in-package lama_msgs-msg)


;//! \htmlinclude PlaceProfile.msg.html

(cl:defclass <PlaceProfile> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (polygon
    :reader polygon
    :initarg :polygon
    :type geometry_msgs-msg:Polygon
    :initform (cl:make-instance 'geometry_msgs-msg:Polygon))
   (exclude_segments
    :reader exclude_segments
    :initarg :exclude_segments
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass PlaceProfile (<PlaceProfile>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PlaceProfile>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PlaceProfile)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-msg:<PlaceProfile> is deprecated: use lama_msgs-msg:PlaceProfile instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <PlaceProfile>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:header-val is deprecated.  Use lama_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'polygon-val :lambda-list '(m))
(cl:defmethod polygon-val ((m <PlaceProfile>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:polygon-val is deprecated.  Use lama_msgs-msg:polygon instead.")
  (polygon m))

(cl:ensure-generic-function 'exclude_segments-val :lambda-list '(m))
(cl:defmethod exclude_segments-val ((m <PlaceProfile>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-msg:exclude_segments-val is deprecated.  Use lama_msgs-msg:exclude_segments instead.")
  (exclude_segments m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PlaceProfile>) ostream)
  "Serializes a message object of type '<PlaceProfile>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'polygon) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'exclude_segments))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'exclude_segments))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PlaceProfile>) istream)
  "Deserializes a message object of type '<PlaceProfile>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'polygon) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'exclude_segments) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'exclude_segments)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PlaceProfile>)))
  "Returns string type for a message object of type '<PlaceProfile>"
  "lama_msgs/PlaceProfile")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PlaceProfile)))
  "Returns string type for a message object of type 'PlaceProfile"
  "lama_msgs/PlaceProfile")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PlaceProfile>)))
  "Returns md5sum for a message object of type '<PlaceProfile>"
  "c55b56133425a18c250b94124f4feaa1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PlaceProfile)))
  "Returns md5sum for a message object of type 'PlaceProfile"
  "c55b56133425a18c250b94124f4feaa1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PlaceProfile>)))
  "Returns full string definition for message of type '<PlaceProfile>"
  (cl:format cl:nil "# 2D Description of a place by some points at obstacle borders~%# The difference with a LaserScan is that some segments can~%# be marked as to be excluded. Such segments will be the segments~%# where the range is the maximum range of the LaserSCan or~%# borders between free and unknown pixels of a costmap.~%~%Header header~%~%geometry_msgs/Polygon polygon~%~%# Segments to exclude, segment i is between point i and i+1.~%# The last segment is between points (n-1) and 0, where n is the number of points.~%int32[] exclude_segments~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PlaceProfile)))
  "Returns full string definition for message of type 'PlaceProfile"
  (cl:format cl:nil "# 2D Description of a place by some points at obstacle borders~%# The difference with a LaserScan is that some segments can~%# be marked as to be excluded. Such segments will be the segments~%# where the range is the maximum range of the LaserSCan or~%# borders between free and unknown pixels of a costmap.~%~%Header header~%~%geometry_msgs/Polygon polygon~%~%# Segments to exclude, segment i is between point i and i+1.~%# The last segment is between points (n-1) and 0, where n is the number of points.~%int32[] exclude_segments~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PlaceProfile>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'polygon))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'exclude_segments) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PlaceProfile>))
  "Converts a ROS message object to a list"
  (cl:list 'PlaceProfile
    (cl:cons ':header (header msg))
    (cl:cons ':polygon (polygon msg))
    (cl:cons ':exclude_segments (exclude_segments msg))
))
