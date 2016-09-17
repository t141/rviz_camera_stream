#include <QApplication>
#include <ros/ros.h>

/* Trying to put this include here results in
Linking CXX executable /home/lucasw/catkin_ws/devel/lib/librviz_camera/librviz_camera
CMakeFiles/librviz_camera.dir/src/panel.cpp.o: In function `Panel::Panel(QWidget*)':
panel.cpp:(.text+0x42): undefined reference to `vtable for Panel'
panel.cpp:(.text+0x4e): undefined reference to `vtable for Panel'
CMakeFiles/librviz_camera.dir/src/panel.cpp.o: In function `Panel::~Panel()':
panel.cpp:(.text+0x310): undefined reference to `vtable for Panel'
panel.cpp:(.text+0x31c): undefined reference to `vtable for Panel'
*/
// #include "librviz_camera/panel.h"
#include "panel.h"

int main(int argc, char **argv)
{
  if (!ros::isInitialized())
  {
    ros::init(argc, argv, "rviz_camera_panel", ros::init_options::AnonymousName);
  }
  QApplication app(argc, argv);
  Panel* panel = new Panel();
  panel->hide();
  app.exec();

  delete panel;
}
