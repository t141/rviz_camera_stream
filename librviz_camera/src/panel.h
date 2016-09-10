#ifndef __RVIZ_CAMERA_STREAM_PANEL_H__
#define __RVIZ_CAMERA_STREAM_PANEL_H__

#include <QWidget>

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
  // void setThickness(int thickness_percent);

private:
  rviz::VisualizationManager* manager_;
  rviz::RenderPanel* render_panel_;
  rviz::Display* camera_;
};
#endif  // __RVIZ_CAMERA_STREAM_PANEL_H__
