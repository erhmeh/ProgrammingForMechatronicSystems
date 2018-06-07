/**
 * This tutorial demonstrates subscribing to a topic using a class method as the callback.
 */

//#ifndef __listener_class_h_
//#define __listener_class_h_


#include "ros/ros.h"
#include "std_msgs/String.h"
#include <deque>
#include <string>

namespace RosListenerTutorial{

class Listener
{
public:
/**
 * @brief Callback for receiving messages 
 *
 * @param[in] msg - The string message
 */
  void callback(const std_msgs::String::ConstPtr& msg);

  /**
   * @brief processing that sorts the string deque alphabetically when deque reaches ten and removes the last five strings
   *
   * @param[in] string - Input string
   */
  void process(std::string input);

  /**
   * @brief returns last string on strings deque
   *
   */
  std::string query_last();

private:
  std::deque<std::string> m_stringDeq;
};


}
//#endif
