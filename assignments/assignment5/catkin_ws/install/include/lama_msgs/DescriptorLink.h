// Generated by gencpp from file lama_msgs/DescriptorLink.msg
// DO NOT EDIT!


#ifndef LAMA_MSGS_MESSAGE_DESCRIPTORLINK_H
#define LAMA_MSGS_MESSAGE_DESCRIPTORLINK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace lama_msgs
{
template <class ContainerAllocator>
struct DescriptorLink_
{
  typedef DescriptorLink_<ContainerAllocator> Type;

  DescriptorLink_()
    : object_id(0)
    , descriptor_id(0)
    , interface_name()  {
    }
  DescriptorLink_(const ContainerAllocator& _alloc)
    : object_id(0)
    , descriptor_id(0)
    , interface_name(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _object_id_type;
  _object_id_type object_id;

   typedef int32_t _descriptor_id_type;
  _descriptor_id_type descriptor_id;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _interface_name_type;
  _interface_name_type interface_name;





  typedef boost::shared_ptr< ::lama_msgs::DescriptorLink_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lama_msgs::DescriptorLink_<ContainerAllocator> const> ConstPtr;

}; // struct DescriptorLink_

typedef ::lama_msgs::DescriptorLink_<std::allocator<void> > DescriptorLink;

typedef boost::shared_ptr< ::lama_msgs::DescriptorLink > DescriptorLinkPtr;
typedef boost::shared_ptr< ::lama_msgs::DescriptorLink const> DescriptorLinkConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lama_msgs::DescriptorLink_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lama_msgs::DescriptorLink_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace lama_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'lama_msgs': ['/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::lama_msgs::DescriptorLink_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lama_msgs::DescriptorLink_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lama_msgs::DescriptorLink_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lama_msgs::DescriptorLink_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lama_msgs::DescriptorLink_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lama_msgs::DescriptorLink_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lama_msgs::DescriptorLink_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7f6d6af0c2f5ed48be6d42a3bb530828";
  }

  static const char* value(const ::lama_msgs::DescriptorLink_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7f6d6af0c2f5ed48ULL;
  static const uint64_t static_value2 = 0xbe6d42a3bb530828ULL;
};

template<class ContainerAllocator>
struct DataType< ::lama_msgs::DescriptorLink_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lama_msgs/DescriptorLink";
  }

  static const char* value(const ::lama_msgs::DescriptorLink_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lama_msgs::DescriptorLink_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# A DescriptorLink is a bond between a Lama object and a descriptor.\n\
\n\
# Id of the Lama object associated with the descriptor (in the database).\n\
int32 object_id\n\
\n\
# Id of the associated descriptor (in the database).\n\
int32 descriptor_id \n\
\n\
# Interface name which also identifies the descriptor type.\n\
string interface_name\n\
";
  }

  static const char* value(const ::lama_msgs::DescriptorLink_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lama_msgs::DescriptorLink_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.object_id);
      stream.next(m.descriptor_id);
      stream.next(m.interface_name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DescriptorLink_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lama_msgs::DescriptorLink_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lama_msgs::DescriptorLink_<ContainerAllocator>& v)
  {
    s << indent << "object_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.object_id);
    s << indent << "descriptor_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.descriptor_id);
    s << indent << "interface_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.interface_name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LAMA_MSGS_MESSAGE_DESCRIPTORLINK_H