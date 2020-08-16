#include <ros/ros.h>
#include <ros/master.h>
#include <rosbag_recorder/RosbagRecorder.hpp>

using namespace rosbag_recorder;

void configureRecorder(rosbag::RecorderOptions *options, std::string filename, std::string filepath, std::vector<std::string> topicList);

int main(int argc, char** argv) {

    ros::init(argc, argv, "rosbag_recorder_node");
    ros::NodeHandle nodeHandle("~");
    rosbag::RecorderOptions options, options2;

    rosbag_recorder::RosbagRecorder recorder(nodeHandle, options);

    std::string filename = recorder.getFilename();
    ROS_INFO_STREAM("filename: " << filename);
    
    std::string filepath = recorder.getFilepath();
    ROS_INFO_STREAM("filepath: " << filepath);
    
    std::vector<std::string> topicList = recorder.getTopicList();
    
    configureRecorder(&options, filename, filepath, topicList);
    
    rosbag_recorder::RosbagRecorder record(nodeHandle, options);
    
    int ret = record.run();

    // run bash script to upload rosbag after node shutdown
    if (ros::master::check()) system("onedrive --synchronize");
    else system("bash ~/catkin_ws/src/av_fyp/rosbag_recorder/scripts/rosbag_uploader.sh");

    return ret;
}

void configureRecorder(rosbag::RecorderOptions *options, std::string filename, 
                    std::string filepath, std::vector<std::string> topicList) {
    
    options->prefix = filepath + "/" + filename;
    
    if (topicList.size() == 0) {
        options->record_all = true;
    } else {
        options->topics = topicList;
    }

    options->append_date = true;
}