;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::GetLamaObject)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'GetLamaObject (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::GETLAMAOBJECT")
  (make-package "LAMA_MSGS::GETLAMAOBJECT"))
(unless (find-package "LAMA_MSGS::GETLAMAOBJECTREQUEST")
  (make-package "LAMA_MSGS::GETLAMAOBJECTREQUEST"))
(unless (find-package "LAMA_MSGS::GETLAMAOBJECTRESPONSE")
  (make-package "LAMA_MSGS::GETLAMAOBJECTRESPONSE"))

(in-package "ROS")





(defclass lama_msgs::GetLamaObjectRequest
  :super ros::object
  :slots (_id ))

(defmethod lama_msgs::GetLamaObjectRequest
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

(defclass lama_msgs::GetLamaObjectResponse
  :super ros::object
  :slots (_object ))

(defmethod lama_msgs::GetLamaObjectResponse
  (:init
   (&key
    ((:object __object) (instance lama_msgs::LamaObject :init))
    )
   (send-super :init)
   (setq _object __object)
   self)
  (:object
   (&rest __object)
   (if (keywordp (car __object))
       (send* _object __object)
     (progn
       (if __object (setq _object (car __object)))
       _object)))
  (:serialization-length
   ()
   (+
    ;; lama_msgs/LamaObject _object
    (send _object :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; lama_msgs/LamaObject _object
       (send _object :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; lama_msgs/LamaObject _object
     (send _object :deserialize buf ptr-) (incf ptr- (send _object :serialization-length))
   ;;
   self)
  )

(defclass lama_msgs::GetLamaObject
  :super ros::object
  :slots ())

(setf (get lama_msgs::GetLamaObject :md5sum-) "7a0bd86202cd08076ac08c680a875047")
(setf (get lama_msgs::GetLamaObject :datatype-) "lama_msgs/GetLamaObject")
(setf (get lama_msgs::GetLamaObject :request) lama_msgs::GetLamaObjectRequest)
(setf (get lama_msgs::GetLamaObject :response) lama_msgs::GetLamaObjectResponse)

(defmethod lama_msgs::GetLamaObjectRequest
  (:response () (instance lama_msgs::GetLamaObjectResponse :init)))

(setf (get lama_msgs::GetLamaObjectRequest :md5sum-) "7a0bd86202cd08076ac08c680a875047")
(setf (get lama_msgs::GetLamaObjectRequest :datatype-) "lama_msgs/GetLamaObjectRequest")
(setf (get lama_msgs::GetLamaObjectRequest :definition-)
      "int32 id
---
LamaObject object


================================================================================
MSG: lama_msgs/LamaObject
# id of lama object in the database, will be unique.
# When adding a vertex into the database, this id will be ignored.
int32 id

# id of lama object in the world (usage is implementation specific).
int32 id_in_world

# name of object
string name

# emitter id and name.
int32 emitter_id
string emitter_name

# type: \"EDGE\" or \"VERTEX\"
int32 type
int32 VERTEX = 1
int32 EDGE = 2

# for edges: start and end vertices
# for vertices: not used
int32[2] references

")

(setf (get lama_msgs::GetLamaObjectResponse :md5sum-) "7a0bd86202cd08076ac08c680a875047")
(setf (get lama_msgs::GetLamaObjectResponse :datatype-) "lama_msgs/GetLamaObjectResponse")
(setf (get lama_msgs::GetLamaObjectResponse :definition-)
      "int32 id
---
LamaObject object


================================================================================
MSG: lama_msgs/LamaObject
# id of lama object in the database, will be unique.
# When adding a vertex into the database, this id will be ignored.
int32 id

# id of lama object in the world (usage is implementation specific).
int32 id_in_world

# name of object
string name

# emitter id and name.
int32 emitter_id
string emitter_name

# type: \"EDGE\" or \"VERTEX\"
int32 type
int32 VERTEX = 1
int32 EDGE = 2

# for edges: start and end vertices
# for vertices: not used
int32[2] references

")



(provide :lama_msgs/GetLamaObject "7a0bd86202cd08076ac08c680a875047")


