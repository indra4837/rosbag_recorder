# Rosbag Recorder

This package contains a rosbag_recorder_node that automatically records all running topics when started.

All rosbag recordings are automatically uploaded to [OneDrive folder.](https://nusu-my.sharepoint.com/:f:/g/personal/e0175651_u_nus_edu/EhfEzxoX4VJFqdl5tZZ7rk8BkUfzA0_pUVZpzS0DA75otg)


## Using the package

### 1. Installation

Build the `rosbag_recorder` package using `catkin_make`

### 2. Using rosbag_recorder

Start node by running rosbag_recorder independently or with system_health_monitor package 
```
roslaunch rosbag_recorder rosbag_recorder.launch

mon launch system_health_monitor system_health_monitor.launch --name=rosmon --disable_diagnostics
```
When the node is killed/shutdown, it will automatically upload the rosbag file to OneDrive
### 3. Subscribed Topics

`All topics indicated`

Records all messages in topics indicated

### 4. Parameters

`filename`

av_sweeper_recordings_YYYY-MM-DD-HH-MM-SS.bag

`filepath`

~/Documents/rosbag_recordings

`topics_record`

1. Specific topics:       
    
    ```
    topics_record:
     - /system_health  
     - /sweeper_mode  
     - /cmd_vel  
    ```

2. All topics (leave the field blank):  
    ```
    topics_record:
    ```