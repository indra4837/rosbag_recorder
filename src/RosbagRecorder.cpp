#include "rosbag_recorder/RosbagRecorder.hpp"

namespace rosbag_recorder {

RosbagRecorder::RosbagRecorder(ros::NodeHandle& nodeHandle, rosbag::RecorderOptions const& options):
    rosbag::Recorder(options)
{
    // rosbag::Recorder(options)
    topicList = retrieveParameters("topics_record", nodeHandle);
    if (!nodeHandle.getParam("filename", filename)) {
        ROS_WARN("Filename not set");
    }
    if (!nodeHandle.getParam("filepath", filepath)) {
        ROS_WARN("Filepath not set");
        // TODO: get boost create_directories to work
        boost::filesystem::create_directories(filepath); 
    }  
}

std::vector<std::string> RosbagRecorder::retrieveParameters(std::string paramRetrieval, ros::NodeHandle& nodeHandle) {
    
    XmlRpc::XmlRpcValue paramList;

    std::vector<std::string> params;

    nodeHandle.getParam(paramRetrieval, paramList);

    for (int j=0; j<paramList.size(); j++) {
        std::string value = static_cast<std::string>(paramList[j]);
        params.push_back(value);
    }

    return params;
}

std::string RosbagRecorder::getFilename() {
    return filename;
}

std::string RosbagRecorder::getFilepath() {
    return filepath;
}

std::vector<std::string> RosbagRecorder::getTopicList() {
    return topicList;
}

} // namespace rosbag_recorder