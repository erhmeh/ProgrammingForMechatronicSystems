;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::PlaceProfile)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'PlaceProfile (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::PLACEPROFILE")
  (make-package "LAMA_MSGS::PLACEPROFILE"))

(in-package "ROS")
;;//! \htmlinclude PlaceProfile.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass lama_msgs::PlaceProfile
  :super ros::object
  :slots (_header _polygon _exclude_segments ))

(defmethod lama_msgs::PlaceProfile
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:polygon __polygon) (instance geometry_msgs::Polygon :init))
    ((:exclude_segments __exclude_segments) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _header __header)
   (setq _polygon __polygon)
   (setq _exclude_segments __exclude_segments)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:polygon
   (&rest __polygon)
   (if (keywordp (car __polygon))
       (send* _polygon __polygon)
     (progn
       (if __polygon (setq _polygon (car __polygon)))
       _polygon)))
  (:exclude_segments
   (&optional __exclude_segments)
   (if __exclude_segments (setq _exclude_segments __exclude_segments)) _exclude_segments)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Polygon _polygon
    (send _polygon :serialization-length)
    ;; int32[] _exclude_segments
    (* 4    (length _exclude_segments)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Polygon _polygon
       (send _polygon :serialize s)
     ;; int32[] _exclude_segments
     (write-long (length _exclude_segments) s)
     (dotimes (i (length _exclude_segments))
       (write-long (elt _exclude_segments i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Polygon _polygon
     (send _polygon :deserialize buf ptr-) (incf ptr- (send _polygon :serialization-length))
   ;; int32[] _exclude_segments
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _exclude_segments (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _exclude_segments i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get lama_msgs::PlaceProfile :md5sum-) "c55b56133425a18c250b94124f4feaa1")
(setf (get lama_msgs::PlaceProfile :datatype-) "lama_msgs/PlaceProfile")
(setf (get lama_msgs::PlaceProfile :definition-)
      "# 2D Description of a place by some points at obstacle borders
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
float32 z
")



(provide :lama_msgs/PlaceProfile "c55b56133425a18c250b94124f4feaa1")


