#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ros/ros.h"
#include "geometry_msgs/PointStamped.h"
#include <std_msgs/Bool.h>
#include <std_msgs/Float64.h>
#include "sensor_msgs/JointState.h"

const double PI = 3.14159265;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void jointControlCallback(const geometry_msgs::PointStamped pointStamped);

    void jointStatesCallback(const sensor_msgs::JointState jointState);

private slots:
    void on_jointControl_Start_PushButton_3_clicked();

    void on_jointControl_J1_Slider_3_actionTriggered(int action);

    void on_jointControl_J2_Slider_3_actionTriggered(int action);

    void on_jointControl_J3_Slider_3_actionTriggered(int action);

    void on_jointControl_Gripper_Checkbox_3_toggled(bool checked);

    void on_jointControl_Reset_PushButton_3_clicked();

    void on_workingModes_3_tabBarClicked(int index);

    void on_positionControl2_Start_PushButton_3_clicked();

    void on_positionControl2_Stop_PushButton_3_clicked();

    void on_positionControlCustom_Start_PushButton_3_clicked();

    void on_basicInfo_GetInfo_PushButton_3_clicked();

    void on_setParameters_Velocity_PushButton_3_clicked();

    void on_setParameters_Acceleration_PushButton_3_clicked();

    void on_setParameters_PlanningTime_PushButton_3_clicked();

    void on_setParameters_NumOfAttempts_PushButton_3_clicked();

    void on_positionControlCustom_Stop_PushButton_4_clicked();

    void on_jointControl_Stop_PushButton_4_clicked();

    void on_positionControlCustom_Reset_PushButton_5_clicked();


private:
    Ui::MainWindow *ui;

    ros::AsyncSpinner *aspinner;

    bool jointControl_gripperState = false;
    bool newJointStates = false;
    sensor_msgs::JointState actualJointStates;

    ros::Publisher jointControl_pub, positionControl_pub, demo_pub, getInfo_pub, setVel_pub, setAcc_pub, setPlanTime_pub, setNumOfAttempts_pub;
    ros::Subscriber jointControlValues_sub, positionControlValues_sub, demoValues_sub, getInfoValues_sub, jointStates_sub;

    geometry_msgs::PointStamped jointControlValues;

};

#endif // MAINWINDOW_H
