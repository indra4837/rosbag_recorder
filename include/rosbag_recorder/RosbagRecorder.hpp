#pragma once

#include <ros/ros.h>
#include <rosbag/recorder.h>
#include <xmlrpcpp/XmlRpcValue.h>
#include <boost/filesystem.hpp>

namespace rosbag_recorder {

class RosbagRecorder : public rosbag::Recorder {
public:
    RosbagRecorder(ros::NodeHandle& nodeHandle, rosbag::RecorderOptions const& options);
    std::string getFilename();
    std::string getFilepath();
    std::vector<std::string> getTopicList();

private:
    ros::NodeHandle nodeHandle_;
    rosbag::RecorderOptions options_;
    
    std::vector<std::string> topicList;
    std::string filename, filepath;

    std::vector<std::string> retrieveParameters(std::string paramRetrieval, ros::NodeHandle& nodeHandle);
};

} // namespace rosbag_recorder