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

  display_service_ = nh_.advertiseService("add_display", &Panel::displayCallback, this);

  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
  timer_->start(100);
}

Panel::~Panel()
{
  delete manager_;
}

void Panel::update()
{
  if (!ros::ok())
    exit(0);
}

bool Panel::displayCallback(librviz_camera::Display::Request& req,
    librviz_camera::Display::Response& res)
{
  if (display_.count(req.name) > 0)
  {
    res.message = "Display name already exists";
    return false;
  }

  res.message = "Creating new display " + req.name + " " + req.type;
  display_[req.name] = manager_->createDisplay(QString::fromStdString(req.type),
                                               QString::fromStdString(req.name),
                                               req.enable);

  return true;
}

// TODO(lucasw) another service to take display name, a subprop name, and a value
// TODO(lucasw) How to handle the value generically?  Initially only handle strings
// then ints and floats
