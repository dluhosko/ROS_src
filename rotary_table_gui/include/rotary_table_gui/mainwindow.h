#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ros/ros.h"
#include "ros/publisher.h"
#include "ros/subscriber.h"
#include "geometry_msgs/PointStamped.h"
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float64.h>
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Byte.h"
#include "scara_msgs/robot_info.h"
#include <stdlib.h>

const double RAD_TO_DEG = 57.2957795130;
const double DEG_TO_RAD = 0.0174532925;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CurrentAngleCallback(const std_msgs::Int32 currentAngle);

    void CurrentWorkingStateCallback(const std_msgs::Int32 currentWorkingState);

    void UselessCallback(const std_msgs::Int32 uselessInfo);

private slots:
    void on_config_OFF_PB_clicked();

    void on_config_READY_PB_clicked();

    void on_config_ON_PB_clicked();

    void on_config_ERROR_PB_clicked();

    void on_relativeControl_slider_SLIDER_actionTriggered(int action);

    void on_relativeControl_slider_PB_clicked();

    void on_relativeControl_input_PB_clicked();

    void on_absoluteControl_slider_SLIDER_actionTriggered(int action);

    void on_absoluteControl_slider_PB_clicked();

    void on_absoluteControl_input_PB_clicked();

    void on_MaxVelocity_input_PB_clicked();

    void on_direction_LEFT_PB_clicked();

    void on_direction_RIGHT_PB_clicked();

    void on_stop_PB_clicked();

    void on_centralStop_PB_clicked();

    void on_direction_LEFT_CB_toggled(bool checked);

    void on_direction_RIGHT_CB_toggled(bool checked);

    //Custom functions
    void printCurrentWorkingStateOnWidget(const int modeNumber);

    void sendWorkingMode(const int modeSelect);

    int hex2dec(char hex_value[]);

private:
    Ui::MainWindow *ui;

    ros::AsyncSpinner *aspinner;

    bool directionOfRotation = true;                //directionOfRotation=true ->right     directionOfRotation=false->left
    double currentAngleDeg = 0.0, currentAngleRad = 0.0;
    char hexString[16];

    std_msgs::Int32 int32_msg;

    ros::Publisher rotate_DEC_pub, rotate_HEX_pub, workingState_pub, useless_pub;
    ros::Subscriber currentAngleDeg_sub, currentWorkingState_sub, status_sub, useless_sub;

};

#endif // MAINWINDOW_H
