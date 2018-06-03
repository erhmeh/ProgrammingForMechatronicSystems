;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::Frontier)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'Frontier (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::FRONTIER")
  (make-package "LAMA_MSGS::FRONTIER"))

(in-package "ROS")
;;//! \htmlinclude Frontier.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass lama_msgs::Frontier
  :super ros::object
  :slots (_p1 _p2 _width _angle ))

(defmethod lama_msgs::Frontier
  (:init
   (&key
    ((:p1 __p1) (instance geometry_msgs::Point :init))
    ((:p2 __p2) (instance geometry_msgs::Point :init))
    ((:width __width) 0.0)
    ((:angle __angle) 0.0)
    )
   (send-super :init)
   (setq _p1 __p1)
   (setq _p2 __p2)
   (setq _width (float __width))
   (setq _angle (float __angle))
   self)
  (:p1
   (&rest __p1)
   (if (keywordp (car __p1))
       (send* _p1 __p1)
     (progn
       (if __p1 (setq _p1 (car __p1)))
       _p1)))
  (:p2
   (&rest __p2)
   (if (keywordp (car __p2))
       (send* _p2 __p2)
     (progn
       (if __p2 (setq _p2 (car __p2)))
       _p2)))
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _p1
    (send _p1 :serialization-length)
    ;; geometry_msgs/Point _p2
    (send _p2 :serialization-length)
    ;; float32 _width
    4
    ;; float32 _angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _p1
       (send _p1 :serialize s)
     ;; geometry_msgs/Point _p2
       (send _p2 :serialize s)
     ;; float32 _width
       (sys::poke _width (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _p1
     (send _p1 :deserialize buf ptr-) (incf ptr- (send _p1 :serialization-length))
   ;; geometry_msgs/Point _p2
     (send _p2 :deserialize buf ptr-) (incf ptr- (send _p2 :serialization-length))
   ;; float32 _width
     (setq _width (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get lama_msgs::Frontier :md5sum-) "626f51fb9d901b07427079891bd87ce3")
(setf (get lama_msgs::Frontier :datatype-) "lama_msgs/Frontier")
(setf (get lama_msgs::Frontier :definition-)
      "# Frontier is a line segment through which a robot can go.

# First point
geometry_msgs/Point p1

# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.
geometry_msgs/Point p2

# Segment length, i.e. width of free space
float32 width

# Angle between x-axis and line between origin and frontier middle. Where x-axis
# and origin refer to the data from which the frontier is computed, in general a LaserScan.
float32 angle

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :lama_msgs/Frontier "626f51fb9d901b07427079891bd87ce3")


