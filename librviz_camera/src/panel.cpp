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
  camera_->subProp("Image Topic")->setValue("image_raw");
  camera_->subProp("Camera Info Topic")->setValue("camera_info");

  // TODO(lucasw) later make a service interface that can create any display...
  // though that just belong in it's own project.
  display_["grid"] = manager_->createDisplay("rviz/Grid", "grid", true);
  display_["grid"]->subProp("Line Style")->setValue("Billboards");
  display_["grid"]->subProp("Color")->setValue(QColor(Qt::yellow));
}

Panel::~Panel()
{
  delete manager_;
}


