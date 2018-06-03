;; Auto-generated. Do not edit!


(when (boundp 'lama_msgs::DescriptorLink)
  (if (not (find-package "LAMA_MSGS"))
    (make-package "LAMA_MSGS"))
  (shadow 'DescriptorLink (find-package "LAMA_MSGS")))
(unless (find-package "LAMA_MSGS::DESCRIPTORLINK")
  (make-package "LAMA_MSGS::DESCRIPTORLINK"))

(in-package "ROS")
;;//! \htmlinclude DescriptorLink.msg.html


(defclass lama_msgs::DescriptorLink
  :super ros::object
  :slots (_object_id _descriptor_id _interface_name ))

(defmethod lama_msgs::DescriptorLink
  (:init
   (&key
    ((:object_id __object_id) 0)
    ((:descriptor_id __descriptor_id) 0)
    ((:interface_name __interface_name) "")
    )
   (send-super :init)
   (setq _object_id (round __object_id))
   (setq _descriptor_id (round __descriptor_id))
   (setq _interface_name (string __interface_name))
   self)
  (:object_id
   (&optional __object_id)
   (if __object_id (setq _object_id __object_id)) _object_id)
  (:descriptor_id
   (&optional __descriptor_id)
   (if __descriptor_id (setq _descriptor_id __descriptor_id)) _descriptor_id)
  (:interface_name
   (&optional __interface_name)
   (if __interface_name (setq _interface_name __interface_name)) _interface_name)
  (:serialization-length
   ()
   (+
    ;; int32 _object_id
    4
    ;; int32 _descriptor_id
    4
    ;; string _interface_name
    4 (length _interface_name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _object_id
       (write-long _object_id s)
     ;; int32 _descriptor_id
       (write-long _descriptor_id s)
     ;; string _interface_name
       (write-long (length _interface_name) s) (princ _interface_name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _object_id
     (setq _object_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _descriptor_id
     (setq _descriptor_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _interface_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _interface_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get lama_msgs::DescriptorLink :md5sum-) "7f6d6af0c2f5ed48be6d42a3bb530828")
(setf (get lama_msgs::DescriptorLink :datatype-) "lama_msgs/DescriptorLink")
(setf (get lama_msgs::DescriptorLink :definition-)
      "# A DescriptorLink is a bond between a Lama object and a descriptor.

# Id of the Lama object associated with the descriptor (in the database).
int32 object_id

# Id of the associated descriptor (in the database).
int32 descriptor_id 

# Interface name which also identifies the descriptor type.
string interface_name

")



(provide :lama_msgs/DescriptorLink "7f6d6af0c2f5ed48be6d42a3bb530828")


