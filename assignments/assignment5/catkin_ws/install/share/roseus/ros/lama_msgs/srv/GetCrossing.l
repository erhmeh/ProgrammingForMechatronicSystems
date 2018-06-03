;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::GetCrossing)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'GetCrossing (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::GETCROSSING")
  (make-package "LAMA_MSGS::GETCROSSING"))
(unless (find-package "LAMA_MSGS::GETCROSSINGREQUEST")
  (make-package "LAMA_MSGS::GETCROSSINGREQUEST"))
(unless (find-package "LAMA_MSGS::GETCROSSINGRESPONSE")
  (make-package "LAMA_MSGS::GETCROSSINGRESPONSE"))

(in-package "ROS")





(defclass lama_msgs::GetCrossingRequest
  :super ros::object
  :slots (_id ))

(defmethod lama_msgs::GetCrossingRequest
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

(defclass lama_msgs::GetCrossingResponse
  :super ros::object
  :slots (_descriptor ))

(defmethod lama_msgs::GetCrossingResponse
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

(defclass lama_msgs::GetCrossing
  :super ros::object
  :slots ())

(setf (get lama_msgs::GetCrossing :md5sum-) "4842af2f1edf5a2e9caf0cee19515bcc")
(setf (get lama_msgs::GetCrossing :datatype-) "lama_msgs/GetCrossing")
(setf (get lama_msgs::GetCrossing :request) lama_msgs::GetCrossingRequest)
(setf (get lama_msgs::GetCrossing :response) lama_msgs::GetCrossingResponse)

(defmethod lama_msgs::GetCrossingRequest
  (:response () (instance lama_msgs::GetCrossingResponse :init)))

(setf (get lama_msgs::GetCrossingRequest :md5sum-) "4842af2f1edf5a2e9caf0cee19515bcc")
(setf (get lama_msgs::GetCrossingRequest :datatype-) "lama_msgs/GetCrossingRequest")
(setf (get lama_msgs::GetCrossingRequest :definition-)
      "int32 id
---
Crossing descriptor


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
")

(setf (get lama_msgs::GetCrossingResponse :md5sum-) "4842af2f1edf5a2e9caf0cee19515bcc")
(setf (get lama_msgs::GetCrossingResponse :datatype-) "lama_msgs/GetCrossingResponse")
(setf (get lama_msgs::GetCrossingResponse :definition-)
      "int32 id
---
Crossing descriptor


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
")



(provide :lama_msgs/GetCrossing "4842af2f1edf5a2e9caf0cee19515bcc")


