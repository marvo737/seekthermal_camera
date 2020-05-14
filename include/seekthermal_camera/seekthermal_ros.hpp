#pragma once

#include <ros/ros.h>
#include <rosconsole/macros_generated.h>
#include <image_transport/image_transport.h>
#include <memory>
#include <seek_thermal/SeekCam.h>
#include <camera_info_manager/camera_info_manager.h>

namespace seekthermal_camera
{
class SeekThermalRos
{
private:
    std::string nodeName;
    ros::NodeHandle& nh;
    ros::NodeHandle& nh_priv;

    image_transport::CameraPublisher pub;
    image_transport::Publisher normalized_pub;
    std::unique_ptr<camera_info_manager::CameraInfoManager> info_manager;
    std::unique_ptr<LibSeek::SeekCam> seek_cam;
    std::string frame_id;

public:
    /**
     * SeekThermalRos constructor.
     * 
     * @param nodeName Node name for the logger
     * @param nh ROS "public" nodehandle
     * @param nh_priv ROS "private" nodehandle
     */
    SeekThermalRos(const std::string nodeName, ros::NodeHandle& nh, ros::NodeHandle& nh_priv);
    ~SeekThermalRos();

    void log(ros::console::levels::Level severity, const char* message);
    bool publish();

};

}