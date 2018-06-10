// Generated by gencpp from file lama_msgs/SetCrossing.msg
// DO NOT EDIT!


#ifndef LAMA_MSGS_MESSAGE_SETCROSSING_H
#define LAMA_MSGS_MESSAGE_SETCROSSING_H

#include <ros/service_traits.h>


#include <lama_msgs/SetCrossingRequest.h>
#include <lama_msgs/SetCrossingResponse.h>


namespace lama_msgs
{

struct SetCrossing
{

typedef SetCrossingRequest Request;
typedef SetCrossingResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetCrossing
} // namespace lama_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::lama_msgs::SetCrossing > {
  static const char* value()
  {
    return "400039bcfb4fed83ffb70a6297f272bc";
  }

  static const char* value(const ::lama_msgs::SetCrossing&) { return value(); }
};

template<>
struct DataType< ::lama_msgs::SetCrossing > {
  static const char* value()
  {
    return "lama_msgs/SetCrossing";
  }

  static const char* value(const ::lama_msgs::SetCrossing&) { return value(); }
};


// service_traits::MD5Sum< ::lama_msgs::SetCrossingRequest> should match 
// service_traits::MD5Sum< ::lama_msgs::SetCrossing > 
template<>
struct MD5Sum< ::lama_msgs::SetCrossingRequest>
{
  static const char* value()
  {
    return MD5Sum< ::lama_msgs::SetCrossing >::value();
  }
  static const char* value(const ::lama_msgs::SetCrossingRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::lama_msgs::SetCrossingRequest> should match 
// service_traits::DataType< ::lama_msgs::SetCrossing > 
template<>
struct DataType< ::lama_msgs::SetCrossingRequest>
{
  static const char* value()
  {
    return DataType< ::lama_msgs::SetCrossing >::value();
  }
  static const char* value(const ::lama_msgs::SetCrossingRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::lama_msgs::SetCrossingResponse> should match 
// service_traits::MD5Sum< ::lama_msgs::SetCrossing > 
template<>
struct MD5Sum< ::lama_msgs::SetCrossingResponse>
{
  static const char* value()
  {
    return MD5Sum< ::lama_msgs::SetCrossing >::value();
  }
  static const char* value(const ::lama_msgs::SetCrossingResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::lama_msgs::SetCrossingResponse> should match 
// service_traits::DataType< ::lama_msgs::SetCrossing > 
template<>
struct DataType< ::lama_msgs::SetCrossingResponse>
{
  static const char* value()
  {
    return DataType< ::lama_msgs::SetCrossing >::value();
  }
  static const char* value(const ::lama_msgs::SetCrossingResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // LAMA_MSGS_MESSAGE_SETCROSSING_H