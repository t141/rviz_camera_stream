#include <QColor>
#include <QGridLayout>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>

#include <ros/ros.h>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>

// #include "librviz_camera/panel.h"
#include "panel.h"

Panel::Panel(QWidget* parent)
  : QWidget(parent)
{
  render_panel_ = new rviz::RenderPanel();
  manager_ = new rviz::VisualizationManager(render_panel_);
  manager_->initialize();
  manager_->startUpdate();

  const bool enabled = true;
  camera_ = manager_->createDisplay("rviz_camera_stream/CameraPub", "rviz camera", enabled);
  ROS_ASSERT(camera_ != NULL);
}

Panel::~Panel()
{
  delete manager_;
}


