#!/bin/bash

source /opt/ros/melodic/setup.bash
source /home/indra/catkin_ws/devel/setup.bash

while rostopic list ; do sleep 1; done
onedrive --synchronize