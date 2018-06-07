/**
 * This tutorial demonstrates subscribing to a topic using a class method as the callback.
 */

#include "ros_listener_tutorial/listener_class.h"
#include <algorithm>

namespace RosListenerTutorial{

void Listener::callback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  process(msg->data);
}

void Listener::process(std::string input){
  m_stringDeq.push_back(input);

  if(m_stringDeq.size()>9){
    std::sort( m_stringDeq.begin(), m_stringDeq.end() );

    for (unsigned int i=0;i<m_stringDeq.size();i++){
      std::cout << "[" << i << "]" << m_stringDeq[i] << std::endl;
    }

    m_stringDeq.erase(m_stringDeq.begin(),m_stringDeq.begin()+5);
  }
}

std::string Listener::query_last(){
  return m_stringDeq[m_stringDeq.size()-1];
}

}
