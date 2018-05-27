;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::LamaObject)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'LamaObject (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::LAMAOBJECT")
  (make-package "LAMA_MSGS::LAMAOBJECT"))

(in-package "ROS")
;;//! \htmlinclude LamaObject.msg.html


(intern "*VERTEX*" (find-package "LAMA_MSGS::LAMAOBJECT"))
(shadow '*VERTEX* (find-package "LAMA_MSGS::LAMAOBJECT"))
(defconstant lama_msgs::LamaObject::*VERTEX* 1)
(intern "*EDGE*" (find-package "LAMA_MSGS::LAMAOBJECT"))
(shadow '*EDGE* (find-package "LAMA_MSGS::LAMAOBJECT"))
(defconstant lama_msgs::LamaObject::*EDGE* 2)
(defclass lama_msgs::LamaObject
  :super ros::object
  :slots (_id _id_in_world _name _emitter_id _emitter_name _type _references ))

(defmethod lama_msgs::LamaObject
  (:init
   (&key
    ((:id __id) 0)
    ((:id_in_world __id_in_world) 0)
    ((:name __name) "")
    ((:emitter_id __emitter_id) 0)
    ((:emitter_name __emitter_name) "")
    ((:type __type) 0)
    ((:references __references) (make-array 2 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _id_in_world (round __id_in_world))
   (setq _name (string __name))
   (setq _emitter_id (round __emitter_id))
   (setq _emitter_name (string __emitter_name))
   (setq _type (round __type))
   (setq _references __references)
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:id_in_world
   (&optional __id_in_world)
   (if __id_in_world (setq _id_in_world __id_in_world)) _id_in_world)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:emitter_id
   (&optional __emitter_id)
   (if __emitter_id (setq _emitter_id __emitter_id)) _emitter_id)
  (:emitter_name
   (&optional __emitter_name)
   (if __emitter_name (setq _emitter_name __emitter_name)) _emitter_name)
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:references
   (&optional __references)
   (if __references (setq _references __references)) _references)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ;; int32 _id_in_world
    4
    ;; string _name
    4 (length _name)
    ;; int32 _emitter_id
    4
    ;; string _emitter_name
    4 (length _emitter_name)
    ;; int32 _type
    4
    ;; int32[2] _references
    (* 4    2)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;; int32 _id_in_world
       (write-long _id_in_world s)
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; int32 _emitter_id
       (write-long _emitter_id s)
     ;; string _emitter_name
       (write-long (length _emitter_name) s) (princ _emitter_name s)
     ;; int32 _type
       (write-long _type s)
     ;; int32[2] _references
     (dotimes (i 2)
       (write-long (elt _references i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _id_in_world
     (setq _id_in_world (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _emitter_id
     (setq _emitter_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _emitter_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _emitter_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _type
     (setq _type (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32[2] _references
   (dotimes (i (length _references))
     (setf (elt _references i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get lama_msgs::LamaObject :md5sum-) "e2747a1741c10b06140b9673d9018102")
(setf (get lama_msgs::LamaObject :datatype-) "lama_msgs/LamaObject")
(setf (get lama_msgs::LamaObject :definition-)
      "# id of lama object in the database, will be unique.
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



(provide :lama_msgs/LamaObject "e2747a1741c10b06140b9673d9018102")


