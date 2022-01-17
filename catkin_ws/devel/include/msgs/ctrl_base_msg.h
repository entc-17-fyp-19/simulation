// Generated by gencpp from file msgs/ctrl_base_msg.msg
// DO NOT EDIT!


#ifndef MSGS_MESSAGE_CTRL_BASE_MSG_H
#define MSGS_MESSAGE_CTRL_BASE_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Quaternion.h>

namespace msgs
{
template <class ContainerAllocator>
struct ctrl_base_msg_
{
  typedef ctrl_base_msg_<ContainerAllocator> Type;

  ctrl_base_msg_()
    : stop(0)
    , angle()  {
    }
  ctrl_base_msg_(const ContainerAllocator& _alloc)
    : stop(0)
    , angle(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _stop_type;
  _stop_type stop;

   typedef  ::geometry_msgs::Quaternion_<ContainerAllocator>  _angle_type;
  _angle_type angle;





  typedef boost::shared_ptr< ::msgs::ctrl_base_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msgs::ctrl_base_msg_<ContainerAllocator> const> ConstPtr;

}; // struct ctrl_base_msg_

typedef ::msgs::ctrl_base_msg_<std::allocator<void> > ctrl_base_msg;

typedef boost::shared_ptr< ::msgs::ctrl_base_msg > ctrl_base_msgPtr;
typedef boost::shared_ptr< ::msgs::ctrl_base_msg const> ctrl_base_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msgs::ctrl_base_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msgs::ctrl_base_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msgs::ctrl_base_msg_<ContainerAllocator1> & lhs, const ::msgs::ctrl_base_msg_<ContainerAllocator2> & rhs)
{
  return lhs.stop == rhs.stop &&
    lhs.angle == rhs.angle;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msgs::ctrl_base_msg_<ContainerAllocator1> & lhs, const ::msgs::ctrl_base_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::msgs::ctrl_base_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msgs::ctrl_base_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msgs::ctrl_base_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msgs::ctrl_base_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msgs::ctrl_base_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msgs::ctrl_base_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msgs::ctrl_base_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2d61acf417dc0ac2964af53176a435fb";
  }

  static const char* value(const ::msgs::ctrl_base_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2d61acf417dc0ac2ULL;
  static const uint64_t static_value2 = 0x964af53176a435fbULL;
};

template<class ContainerAllocator>
struct DataType< ::msgs::ctrl_base_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msgs/ctrl_base_msg";
  }

  static const char* value(const ::msgs::ctrl_base_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msgs::ctrl_base_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 stop\n"
"geometry_msgs/Quaternion angle\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::msgs::ctrl_base_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msgs::ctrl_base_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stop);
      stream.next(m.angle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ctrl_base_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msgs::ctrl_base_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msgs::ctrl_base_msg_<ContainerAllocator>& v)
  {
    s << indent << "stop: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.stop);
    s << indent << "angle: ";
    s << std::endl;
    Printer< ::geometry_msgs::Quaternion_<ContainerAllocator> >::stream(s, indent + "  ", v.angle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSGS_MESSAGE_CTRL_BASE_MSG_H