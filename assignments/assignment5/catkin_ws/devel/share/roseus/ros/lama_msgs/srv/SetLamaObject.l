;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::SetLamaObject)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'SetLamaObject (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::SETLAMAOBJECT")
  (make-package "LAMA_MSGS::SETLAMAOBJECT"))
(unless (find-package "LAMA_MSGS::SETLAMAOBJECTREQUEST")
  (make-package "LAMA_MSGS::SETLAMAOBJECTREQUEST"))
(unless (find-package "LAMA_MSGS::SETLAMAOBJECTRESPONSE")
  (make-package "LAMA_MSGS::SETLAMAOBJECTRESPONSE"))

(in-package "ROS")





(defclass lama_msgs::SetLamaObjectRequest
  :super ros::object
  :slots (_object ))

(defmethod lama_msgs::SetLamaObjectRequest
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

(defclass lama_msgs::SetLamaObjectResponse
  :super ros::object
  :slots (_id ))

(defmethod lama_msgs::SetLamaObjectResponse
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

(defclass lama_msgs::SetLamaObject
  :super ros::object
  :slots ())

(setf (get lama_msgs::SetLamaObject :md5sum-) "f191a122fd81f40804a5436e7a94b04c")
(setf (get lama_msgs::SetLamaObject :datatype-) "lama_msgs/SetLamaObject")
(setf (get lama_msgs::SetLamaObject :request) lama_msgs::SetLamaObjectRequest)
(setf (get lama_msgs::SetLamaObject :response) lama_msgs::SetLamaObjectResponse)

(defmethod lama_msgs::SetLamaObjectRequest
  (:response () (instance lama_msgs::SetLamaObjectResponse :init)))

(setf (get lama_msgs::SetLamaObjectRequest :md5sum-) "f191a122fd81f40804a5436e7a94b04c")
(setf (get lama_msgs::SetLamaObjectRequest :datatype-) "lama_msgs/SetLamaObjectRequest")
(setf (get lama_msgs::SetLamaObjectRequest :definition-)
      "LamaObject object

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

---
int32 id

")

(setf (get lama_msgs::SetLamaObjectResponse :md5sum-) "f191a122fd81f40804a5436e7a94b04c")
(setf (get lama_msgs::SetLamaObjectResponse :datatype-) "lama_msgs/SetLamaObjectResponse")
(setf (get lama_msgs::SetLamaObjectResponse :definition-)
      "LamaObject object

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

---
int32 id

")



(provide :lama_msgs/SetLamaObject "f191a122fd81f40804a5436e7a94b04c")


