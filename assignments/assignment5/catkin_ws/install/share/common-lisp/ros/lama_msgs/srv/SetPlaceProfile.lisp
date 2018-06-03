; Auto-generated. Do not edit!


(cl:in-package lama_msgs-srv)


;//! \htmlinclude SetPlaceProfile-request.msg.html

(cl:defclass <SetPlaceProfile-request> (roslisp-msg-protocol:ros-message)
  ((descriptor
    :reader descriptor
    :initarg :descriptor
    :type lama_msgs-msg:PlaceProfile
    :initform (cl:make-instance 'lama_msgs-msg:PlaceProfile)))
)

(cl:defclass SetPlaceProfile-request (<SetPlaceProfile-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetPlaceProfile-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetPlaceProfile-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<SetPlaceProfile-request> is deprecated: use lama_msgs-srv:SetPlaceProfile-request instead.")))

(cl:ensure-generic-function 'descriptor-val :lambda-list '(m))
(cl:defmethod descriptor-val ((m <SetPlaceProfile-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:descriptor-val is deprecated.  Use lama_msgs-srv:descriptor instead.")
  (descriptor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetPlaceProfile-request>) ostream)
  "Serializes a message object of type '<SetPlaceProfile-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'descriptor) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetPlaceProfile-request>) istream)
  "Deserializes a message object of type '<SetPlaceProfile-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'descriptor) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetPlaceProfile-request>)))
  "Returns string type for a service object of type '<SetPlaceProfile-request>"
  "lama_msgs/SetPlaceProfileRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetPlaceProfile-request)))
  "Returns string type for a service object of type 'SetPlaceProfile-request"
  "lama_msgs/SetPlaceProfileRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetPlaceProfile-request>)))
  "Returns md5sum for a message object of type '<SetPlaceProfile-request>"
  "33f8b6a8c5bc01cf725509cfd487af55")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetPlaceProfile-request)))
  "Returns md5sum for a message object of type 'SetPlaceProfile-request"
  "33f8b6a8c5bc01cf725509cfd487af55")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetPlaceProfile-request>)))
  "Returns full string definition for message of type '<SetPlaceProfile-request>"
  (cl:format cl:nil "PlaceProfile descriptor~%~%================================================================================~%MSG: lama_msgs/PlaceProfile~%# 2D Description of a place by some points at obstacle borders~%# The difference with a LaserScan is that some segments can~%# be marked as to be excluded. Such segments will be the segments~%# where the range is the maximum range of the LaserSCan or~%# borders between free and unknown pixels of a costmap.~%~%Header header~%~%geometry_msgs/Polygon polygon~%~%# Segments to exclude, segment i is between point i and i+1.~%# The last segment is between points (n-1) and 0, where n is the number of points.~%int32[] exclude_segments~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetPlaceProfile-request)))
  "Returns full string definition for message of type 'SetPlaceProfile-request"
  (cl:format cl:nil "PlaceProfile descriptor~%~%================================================================================~%MSG: lama_msgs/PlaceProfile~%# 2D Description of a place by some points at obstacle borders~%# The difference with a LaserScan is that some segments can~%# be marked as to be excluded. Such segments will be the segments~%# where the range is the maximum range of the LaserSCan or~%# borders between free and unknown pixels of a costmap.~%~%Header header~%~%geometry_msgs/Polygon polygon~%~%# Segments to exclude, segment i is between point i and i+1.~%# The last segment is between points (n-1) and 0, where n is the number of points.~%int32[] exclude_segments~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetPlaceProfile-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'descriptor))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetPlaceProfile-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetPlaceProfile-request
    (cl:cons ':descriptor (descriptor msg))
))
;//! \htmlinclude SetPlaceProfile-response.msg.html

(cl:defclass <SetPlaceProfile-response> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0))
)

(cl:defclass SetPlaceProfile-response (<SetPlaceProfile-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetPlaceProfile-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetPlaceProfile-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lama_msgs-srv:<SetPlaceProfile-response> is deprecated: use lama_msgs-srv:SetPlaceProfile-response instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <SetPlaceProfile-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lama_msgs-srv:id-val is deprecated.  Use lama_msgs-srv:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetPlaceProfile-response>) ostream)
  "Serializes a message object of type '<SetPlaceProfile-response>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetPlaceProfile-response>) istream)
  "Deserializes a message object of type '<SetPlaceProfile-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetPlaceProfile-response>)))
  "Returns string type for a service object of type '<SetPlaceProfile-response>"
  "lama_msgs/SetPlaceProfileResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetPlaceProfile-response)))
  "Returns string type for a service object of type 'SetPlaceProfile-response"
  "lama_msgs/SetPlaceProfileResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetPlaceProfile-response>)))
  "Returns md5sum for a message object of type '<SetPlaceProfile-response>"
  "33f8b6a8c5bc01cf725509cfd487af55")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetPlaceProfile-response)))
  "Returns md5sum for a message object of type 'SetPlaceProfile-response"
  "33f8b6a8c5bc01cf725509cfd487af55")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetPlaceProfile-response>)))
  "Returns full string definition for message of type '<SetPlaceProfile-response>"
  (cl:format cl:nil "int32 id~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetPlaceProfile-response)))
  "Returns full string definition for message of type 'SetPlaceProfile-response"
  (cl:format cl:nil "int32 id~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetPlaceProfile-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetPlaceProfile-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetPlaceProfile-response
    (cl:cons ':id (id msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetPlaceProfile)))
  'SetPlaceProfile-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetPlaceProfile)))
  'SetPlaceProfile-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetPlaceProfile)))
  "Returns string type for a service object of type '<SetPlaceProfile>"
  "lama_msgs/SetPlaceProfile")