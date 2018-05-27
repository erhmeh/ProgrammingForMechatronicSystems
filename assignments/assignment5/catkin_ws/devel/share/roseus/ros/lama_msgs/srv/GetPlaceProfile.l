;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::GetPlaceProfile)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'GetPlaceProfile (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::GETPLACEPROFILE")
  (make-package "LAMA_MSGS::GETPLACEPROFILE"))
(unless (find-package "LAMA_MSGS::GETPLACEPROFILEREQUEST")
  (make-package "LAMA_MSGS::GETPLACEPROFILEREQUEST"))
(unless (find-package "LAMA_MSGS::GETPLACEPROFILERESPONSE")
  (make-package "LAMA_MSGS::GETPLACEPROFILERESPONSE"))

(in-package "ROS")





(defclass lama_msgs::GetPlaceProfileRequest
  :super ros::object
  :slots (_id ))

(defmethod lama_msgs::GetPlaceProfileRequest
  (:init
   (&key
    ((:id __id) 0)
    )
   (send-super :init)
   (setq _id (round __id))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass lama_msgs::GetPlaceProfileResponse
  :super ros::object
  :slots (_descriptor ))

(defmethod lama_msgs::GetPlaceProfileResponse
  (:init
   (&key
    ((:descriptor __descriptor) (instance lama_msgs::PlaceProfile :init))
    )
   (send-super :init)
   (setq _descriptor __descriptor)
   self)
  (:descriptor
   (&rest __descriptor)
   (if (keywordp (car __descriptor))
       (send* _descriptor __descriptor)
     (progn
       (if __descriptor (setq _descriptor (car __descriptor)))
       _descriptor)))
  (:serialization-length
   ()
   (+
    ;; lama_msgs/PlaceProfile _descriptor
    (send _descriptor :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; lama_msgs/PlaceProfile _descriptor
       (send _descriptor :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; lama_msgs/PlaceProfile _descriptor
     (send _descriptor :deserialize buf ptr-) (incf ptr- (send _descriptor :serialization-length))
   ;;
   self)
  )

(defclass lama_msgs::GetPlaceProfile
  :super ros::object
  :slots ())

(setf (get lama_msgs::GetPlaceProfile :md5sum-) "1618b57072692f88573b9b9dff6edef8")
(setf (get lama_msgs::GetPlaceProfile :datatype-) "lama_msgs/GetPlaceProfile")
(setf (get lama_msgs::GetPlaceProfile :request) lama_msgs::GetPlaceProfileRequest)
(setf (get lama_msgs::GetPlaceProfile :response) lama_msgs::GetPlaceProfileResponse)

(defmethod lama_msgs::GetPlaceProfileRequest
  (:response () (instance lama_msgs::GetPlaceProfileResponse :init)))

(setf (get lama_msgs::GetPlaceProfileRequest :md5sum-) "1618b57072692f88573b9b9dff6edef8")
(setf (get lama_msgs::GetPlaceProfileRequest :datatype-) "lama_msgs/GetPlaceProfileRequest")
(setf (get lama_msgs::GetPlaceProfileRequest :definition-)
      "int32 id
---
PlaceProfile descriptor


================================================================================
MSG: lama_msgs/PlaceProfile
# 2D Description of a place by some points at obstacle borders
# The difference with a LaserScan is that some segments can
# be marked as to be excluded. Such segments will be the segments
# where the range is the maximum range of the LaserSCan or
# borders between free and unknown pixels of a costmap.

Header header

geometry_msgs/Polygon polygon

# Segments to exclude, segment i is between point i and i+1.
# The last segment is between points (n-1) and 0, where n is the number of points.
int32[] exclude_segments

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Polygon
#A specification of a polygon where the first and last points are assumed to be connected
Point32[] points

================================================================================
MSG: geometry_msgs/Point32
# This contains the position of a point in free space(with 32 bits of precision).
# It is recommeded to use Point wherever possible instead of Point32.  
# 
# This recommendation is to promote interoperability.  
#
# This message is designed to take up less space when sending
# lots of points at once, as in the case of a PointCloud.  

float32 x
float32 y
")

(setf (get lama_msgs::GetPlaceProfileResponse :md5sum-) "1618b57072692f88573b9b9dff6edef8")
(setf (get lama_msgs::GetPlaceProfileResponse :datatype-) "lama_msgs/GetPlaceProfileResponse")
(setf (get lama_msgs::GetPlaceProfileResponse :definition-)
      "int32 id
---
PlaceProfile descriptor


================================================================================
MSG: lama_msgs/PlaceProfile
# 2D Description of a place by some points at obstacle borders
# The difference with a LaserScan is that some segments can
# be marked as to be excluded. Such segments will be the segments
# where the range is the maximum range of the LaserSCan or
# borders between free and unknown pixels of a costmap.

Header header

geometry_msgs/Polygon polygon

# Segments to exclude, segment i is between point i and i+1.
# The last segment is between points (n-1) and 0, where n is the number of points.
int32[] exclude_segments

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Polygon
#A specification of a polygon where the first and last points are assumed to be connected
Point32[] points

================================================================================
MSG: geometry_msgs/Point32
# This contains the position of a point in free space(with 32 bits of precision).
# It is recommeded to use Point wherever possible instead of Point32.  
# 
# This recommendation is to promote interoperability.  
#
# This message is designed to take up less space when sending
# lots of points at once, as in the case of a PointCloud.  

float32 x
float32 y
")



(provide :lama_msgs/GetPlaceProfile "1618b57072692f88573b9b9dff6edef8")


