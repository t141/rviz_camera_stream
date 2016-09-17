#ifndef __RVIZ_CAMERA_STREAM_PANEL_H__
#define __RVIZ_CAMERA_STREAM_PANEL_H__

#include <librviz_camera/Display.h>
#include <map>
#include <QTimer>
#include <QWidget>
#include <ros/ros.h>

namespace rviz
{
class Display;
class RenderPanel;
class VisualizationManager;
}

class Panel: public QWidget
{
Q_OBJECT
public:
  Panel(QWidget* parent = 0);
  virtual ~Panel();

private Q_SLOTS:
  void update();

private:
  ros::NodeHandle nh_;
  rviz::VisualizationManager* manager_;
  rviz::RenderPanel* render_panel_;
  rviz::Display* camera_;
  ros::ServiceServer display_service_;

  bool displayCallback(librviz_camera::DisplayRequest& req,
    librviz_camera::DisplayResponse& res);

  QTimer* timer_;

  std::map<std::string, rviz::Display*> display_;
};
#endif  // __RVIZ_CAMERA_STREAM_PANEL_H__
