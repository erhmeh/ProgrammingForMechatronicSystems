;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::SetCrossing)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'SetCrossing (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::SETCROSSING")
  (make-package "LAMA_MSGS::SETCROSSING"))
(unless (find-package "LAMA_MSGS::SETCROSSINGREQUEST")
  (make-package "LAMA_MSGS::SETCROSSINGREQUEST"))
(unless (find-package "LAMA_MSGS::SETCROSSINGRESPONSE")
  (make-package "LAMA_MSGS::SETCROSSINGRESPONSE"))

(in-package "ROS")





(defclass lama_msgs::SetCrossingRequest
  :super ros::object
  :slots (_descriptor ))

(defmethod lama_msgs::SetCrossingRequest
  (:init
   (&key
    ((:descriptor __descriptor) (instance lama_msgs::Crossing :init))
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
    ;; lama_msgs/Crossing _descriptor
    (send _descriptor :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; lama_msgs/Crossing _descriptor
       (send _descriptor :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; lama_msgs/Crossing _descriptor
     (send _descriptor :deserialize buf ptr-) (incf ptr- (send _descriptor :serialization-length))
   ;;
   self)
  )

(defclass lama_msgs::SetCrossingResponse
  :super ros::object
  :slots (_id ))

(defmethod lama_msgs::SetCrossingResponse
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

(defclass lama_msgs::SetCrossing
  :super ros::object
  :slots ())

(setf (get lama_msgs::SetCrossing :md5sum-) "400039bcfb4fed83ffb70a6297f272bc")
(setf (get lama_msgs::SetCrossing :datatype-) "lama_msgs/SetCrossing")
(setf (get lama_msgs::SetCrossing :request) lama_msgs::SetCrossingRequest)
(setf (get lama_msgs::SetCrossing :response) lama_msgs::SetCrossingResponse)

(defmethod lama_msgs::SetCrossingRequest
  (:response () (instance lama_msgs::SetCrossingResponse :init)))

(setf (get lama_msgs::SetCrossingRequest :md5sum-) "400039bcfb4fed83ffb70a6297f272bc")
(setf (get lama_msgs::SetCrossingRequest :datatype-) "lama_msgs/SetCrossingRequest")
(setf (get lama_msgs::SetCrossingRequest :definition-)
      "Crossing descriptor

================================================================================
MSG: lama_msgs/Crossing
# The main aim of a crossing is to store frontier information.

# Crossing center.
geometry_msgs/Point center

# Crossing radius.
float32 radius

# Max. range of the data used to compute the crossing.
float32 max_range

Frontier[] frontiers

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: lama_msgs/Frontier
# Frontier is a line segment through which a robot can go.

# First point
geometry_msgs/Point p1

# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.
geometry_msgs/Point p2

# Segment length, i.e. width of free space
float32 width

# Angle between x-axis and line between origin and frontier middle. Where x-axis
# and origin refer to the data from which the frontier is computed, in general a LaserScan.
float32 angle
---
int32 id

")

(setf (get lama_msgs::SetCrossingResponse :md5sum-) "400039bcfb4fed83ffb70a6297f272bc")
(setf (get lama_msgs::SetCrossingResponse :datatype-) "lama_msgs/SetCrossingResponse")
(setf (get lama_msgs::SetCrossingResponse :definition-)
      "Crossing descriptor

================================================================================
MSG: lama_msgs/Crossing
# The main aim of a crossing is to store frontier information.

# Crossing center.
geometry_msgs/Point center

# Crossing radius.
float32 radius

# Max. range of the data used to compute the crossing.
float32 max_range

Frontier[] frontiers

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: lama_msgs/Frontier
# Frontier is a line segment through which a robot can go.

# First point
geometry_msgs/Point p1

# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.
geometry_msgs/Point p2

# Segment length, i.e. width of free space
float32 width

# Angle between x-axis and line between origin and frontier middle. Where x-axis
# and origin refer to the data from which the frontier is computed, in general a LaserScan.
float32 angle
---
int32 id

")



(provide :lama_msgs/SetCrossing "400039bcfb4fed83ffb70a6297f272bc")


