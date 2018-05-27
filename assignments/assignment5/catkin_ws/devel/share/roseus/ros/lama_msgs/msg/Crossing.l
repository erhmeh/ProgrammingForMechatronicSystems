;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::Crossing)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'Crossing (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::CROSSING")
  (make-package "LAMA_MSGS::CROSSING"))

(in-package "ROS")
;;//! \htmlinclude Crossing.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass lama_msgs::Crossing
  :super ros::object
  :slots (_center _radius _max_range _frontiers ))

(defmethod lama_msgs::Crossing
  (:init
   (&key
    ((:center __center) (instance geometry_msgs::Point :init))
    ((:radius __radius) 0.0)
    ((:max_range __max_range) 0.0)
    ((:frontiers __frontiers) (let (r) (dotimes (i 0) (push (instance lama_msgs::Frontier :init) r)) r))
    )
   (send-super :init)
   (setq _center __center)
   (setq _radius (float __radius))
   (setq _max_range (float __max_range))
   (setq _frontiers __frontiers)
   self)
  (:center
   (&rest __center)
   (if (keywordp (car __center))
       (send* _center __center)
     (progn
       (if __center (setq _center (car __center)))
       _center)))
  (:radius
   (&optional __radius)
   (if __radius (setq _radius __radius)) _radius)
  (:max_range
   (&optional __max_range)
   (if __max_range (setq _max_range __max_range)) _max_range)
  (:frontiers
   (&rest __frontiers)
   (if (keywordp (car __frontiers))
       (send* _frontiers __frontiers)
     (progn
       (if __frontiers (setq _frontiers (car __frontiers)))
       _frontiers)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _center
    (send _center :serialization-length)
    ;; float32 _radius
    4
    ;; float32 _max_range
    4
    ;; lama_msgs/Frontier[] _frontiers
    (apply #'+ (send-all _frontiers :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _center
       (send _center :serialize s)
     ;; float32 _radius
       (sys::poke _radius (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _max_range
       (sys::poke _max_range (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; lama_msgs/Frontier[] _frontiers
     (write-long (length _frontiers) s)
     (dolist (elem _frontiers)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _center
     (send _center :deserialize buf ptr-) (incf ptr- (send _center :serialization-length))
   ;; float32 _radius
     (setq _radius (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _max_range
     (setq _max_range (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; lama_msgs/Frontier[] _frontiers
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _frontiers (let (r) (dotimes (i n) (push (instance lama_msgs::Frontier :init) r)) r))
     (dolist (elem- _frontiers)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get lama_msgs::Crossing :md5sum-) "67addd09c3278311b7859a9f2670cdb2")
(setf (get lama_msgs::Crossing :datatype-) "lama_msgs/Crossing")
(setf (get lama_msgs::Crossing :definition-)
      "# The main aim of a crossing is to store frontier information.

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



(provide :lama_msgs/Crossing "67addd09c3278311b7859a9f2670cdb2")


