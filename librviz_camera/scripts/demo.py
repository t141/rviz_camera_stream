#!/usr/bin/env python
# Lucas Walter
#
# create a rviz_camera_stream/CameraPub
# set property "Image Topic" to "image_raw"

import rospy

from librviz_camera.srv import *

rospy.init_node('librviz_service_demo')
rospy.wait_for_service('add_display')
add_display = rospy.ServiceProxy('add_display', Display)
rospy.wait_for_service('set_property')
set_property = rospy.ServiceProxy('set_property', Property)

display_req = DisplayRequest()
display_req.name = "rviz_camera"
display_req.type = "rviz_camera_stream/CameraPub"
display_req.enable = True

try:
    display_resp = add_display(display_req)
    rospy.loginfo(display_resp)
except rospy.service.ServiceException as e:
    rospy.logerr(e)

property_req = PropertyRequest()
property_req.display = display_req.name
property_req.property = "Image Topic"
property_req.type = "string"
property_req.string_value = "image_raw"

try:
    property_resp = set_property(property_req)
    rospy.loginfo(property_resp)
except rospy.service.ServiceException as e:
    rospy.logerr(e)

# set property "Camera Info Topic" to "camera_info"
property_req = PropertyRequest()
property_req.display = display_req.name
property_req.property = "Camera Info Topic"
property_req.type = "string"
property_req.string_value = "camera_info"

try:
    property_resp = set_property(property_req)
    rospy.loginfo(property_resp)
except rospy.service.ServiceException as e:
    rospy.logerr(e)

# add a grid
display_req = DisplayRequest()
display_req.name = "grid"
display_req.type = "rviz/Grid"
display_req.enable = True

try:
    display_resp = add_display(display_req)
    rospy.loginfo(display_resp)
except rospy.service.ServiceException as e:
    rospy.logerr(e)
