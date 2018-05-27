;; Auto-generated. Do not edit!


(when (boundp 'a5_help::RequestGoal)
  (if (not (find-package "A5_HELP"))
    (make-package "A5_HELP"))
  (shadow 'RequestGoal (find-package "A5_HELP")))
(unless (find-package "A5_HELP::REQUESTGOAL")
  (make-package "A5_HELP::REQUESTGOAL"))
(unless (find-package "A5_HELP::REQUESTGOALREQUEST")
  (make-package "A5_HELP::REQUESTGOALREQUEST"))
(unless (find-package "A5_HELP::REQUESTGOALRESPONSE")
  (make-package "A5_HELP::REQUESTGOALRESPONSE"))

(in-package "ROS")





(defclass a5_help::RequestGoalRequest
  :super ros::object
  :slots (_x _y ))

(defmethod a5_help::RequestGoalRequest
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass a5_help::RequestGoalResponse
  :super ros::object
  :slots (_ack ))

(defmethod a5_help::RequestGoalResponse
  (:init
   (&key
    ((:ack __ack) nil)
    )
   (send-super :init)
   (setq _ack __ack)
   self)
  (:ack
   (&optional __ack)
   (if __ack (setq _ack __ack)) _ack)
  (:serialization-length
   ()
   (+
    ;; bool _ack
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _ack
       (if _ack (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _ack
     (setq _ack (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass a5_help::RequestGoal
  :super ros::object
  :slots ())

(setf (get a5_help::RequestGoal :md5sum-) "9befc60e44ef239556519170390f8bbe")
(setf (get a5_help::RequestGoal :datatype-) "a5_help/RequestGoal")
(setf (get a5_help::RequestGoal :request) a5_help::RequestGoalRequest)
(setf (get a5_help::RequestGoal :response) a5_help::RequestGoalResponse)

(defmethod a5_help::RequestGoalRequest
  (:response () (instance a5_help::RequestGoalResponse :init)))

(setf (get a5_help::RequestGoalRequest :md5sum-) "9befc60e44ef239556519170390f8bbe")
(setf (get a5_help::RequestGoalRequest :datatype-) "a5_help/RequestGoalRequest")
(setf (get a5_help::RequestGoalRequest :definition-)
      "float64 x
float64 y
---
bool ack

")

(setf (get a5_help::RequestGoalResponse :md5sum-) "9befc60e44ef239556519170390f8bbe")
(setf (get a5_help::RequestGoalResponse :datatype-) "a5_help/RequestGoalResponse")
(setf (get a5_help::RequestGoalResponse :definition-)
      "float64 x
float64 y
---
bool ack

")



(provide :a5_help/RequestGoal "9befc60e44ef239556519170390f8bbe")


