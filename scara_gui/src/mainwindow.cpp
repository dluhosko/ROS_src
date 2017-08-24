#include "../include/scara_gui/mainwindow.h"
#include "ui_mainwindow.h"

#include <pluginlib/class_list_macros.h>
#include <QStringList>
#include "ros/ros.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int argc;
    char **argv;
    ros::init(argc, argv, "scara_gui_node");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_jointControl_Start_PushButton_3_clicked()
{

    ui->status_joint1pos_rad_3->display(ui->jointControl_J1_Slider_3->value() / 100.0);
    ui->status_joint2pos_rad_3->display(ui->jointControl_J2_Slider_3->value() / 100.0);
    ui->status_joint3pos_rad_3->display(ui->jointControl_J3_Slider_3->value() / 100.0);

    //Len test
    ui->jointControl_J1_LineEdit->setText(QString::number(ui->jointControl_J1_Slider_3->value() / 100.0) + "rad");
    ui->jointControl_J2_LineEdit->setText(QString::number(ui->jointControl_J2_Slider_3->value() / 100.0) + "rad");
    ui->jointControl_J3_LineEdit->setText(QString::number(ui->jointControl_J3_Slider_3->value() / 100.0) + "rad");


    //Send the values to ROS!
    //.............

}


void MainWindow::on_jointControl_J1_Slider_3_actionTriggered(int action)
{
    ui->jointControl_J1_LineEdit->setText(QString::number(ui->jointControl_J1_Slider_3->value() / 100.0) + "rad");


}
void MainWindow::on_jointControl_J2_Slider_3_actionTriggered(int action)
{
    ui->jointControl_J2_LineEdit->setText(QString::number(ui->jointControl_J2_Slider_3->value() / 100.0) + "rad");
}
void MainWindow::on_jointControl_J3_Slider_3_actionTriggered(int action)
{
    ui->jointControl_J3_LineEdit->setText(QString::number(ui->jointControl_J3_Slider_3->value() / 100.0) + "rad");
}

void MainWindow::on_jointControl_Gripper_Checkbox_3_toggled(bool checked)
{
    if (checked){
        ui->jointControl_gripper_LineEdit->setText("ON!");
    }else{
        ui->jointControl_gripper_LineEdit->setText("OFF!");
    }
}


void MainWindow::on_jointControl_Reset_PushButton_3_clicked()
{
    ui->jointControl_J1_Slider_3->setValue(0);
    ui->jointControl_J2_Slider_3->setValue(0);
    ui->jointControl_J3_Slider_3->setValue(0);
    ui->jointControl_J1_LineEdit->setText(QString::number(0.0) + "rad");
    ui->jointControl_J2_LineEdit->setText(QString::number(0.0) + "rad");
    ui->jointControl_J3_LineEdit->setText(QString::number(0.0) + "rad");

    ui->jointControl_Gripper_Checkbox_3->setChecked(false);
    ui->jointControl_gripper_LineEdit->setText("OFF!");


}

void MainWindow::on_workingModes_3_tabBarClicked(int index)
{
    if (index == 0){
        ui->currentWorkingMode_LineEdit->setText("Info");
    }else{
        ui->currentWorkingMode_LineEdit->setText(QString::number(index));
    }

}

void MainWindow::on_positionControl1_Start_PushButton_3_clicked()
{
    ui->positionControl1_LineEdit->setText("DEMO application 1 RUNNING!");
}

void MainWindow::on_positionControl1_Stop_PushButton_3_clicked()
{
    ui->positionControl1_LineEdit->setText("DEMO application 1 STOPPED !");
}

void MainWindow::on_positionControl2_Start_PushButton_3_clicked()
{
    ui->positionControl2_LineEdit->setText("DEMO application 2 RUNNING!");
}

void MainWindow::on_positionControl2_Stop_PushButton_3_clicked()
{
    ui->positionControl2_LineEdit->setText("DEMO application 2 STOPPED!");
}

void MainWindow::on_positionControlCustom_Start_PushButton_3_clicked()
{
    double x = ui->positionControlCustom_X_LineEdit_3->text().toDouble();
    double y = ui->positionControlCustom_Y_LineEdit_3->text().toDouble();
    double z = ui->positionControlCustom_Z_LineEdit_3->text().toDouble();

    //Len test
    ui->status_joint1vel_3->display(x);
    ui->status_joint2vel_3->display(y);
    ui->status_joint3vel_3->display(z);


}

void MainWindow::on_basicInfo_GetInfo_PushButton_3_clicked()
{
    //Tu budem citat hodnoty z rosu a zapisovat do nizzsich..

    //Len test
    ui->basicInfo_RobotModel_TextBrowser_3->setText("Sem pride robot model");
    ui->basicInfo_ReferenceFrame_TextBrowser_3->setText("Sem pride reference frame");
    ui->basicInfo_EffectorLink_TextBrowser_3->setText("sem pride efector link");
    ui->basicInfo_ActiveJoints_TextBrowser_3->setText("Sem pride active joints");

    ui->basicInfo_X_LCDnum_3->display(0.1);
    ui->basicInfo_Y_LCDnum_6->display(0.2);
    ui->basicInfo_Z_LCDnum_3->display(0.3);
    ui->basicInfo_R_LCDnum_3->display(0.4);
    ui->basicInfo_P_LCDnum_3->display(0.5);
    ui->basicInfo_Y_LCDnum_5->display(0.6);
    ui->basicInfo_W_LCDnum_3->display(0.7);

}

void MainWindow::on_setParameters_Velocity_PushButton_3_clicked()
{
    double vel = ui->setParameters_Velocity_LineEdit_3->text().toDouble();

    //Len test
    ui->status_joint1acc_3->display(vel);

}

void MainWindow::on_setParameters_Acceleration_PushButton_3_clicked()
{
    double acc = ui->setParameters_Acceleration_LineEdit_3->text().toDouble();

    //Len test
    ui->status_joint1acc_3->display(acc);
}

void MainWindow::on_setParameters_PlanningTime_PushButton_3_clicked()
{
    double planningTime = ui->setParameters_PlanningTime_LineEdit_3->text().toDouble();

    //Len test
    ui->status_joint1acc_3->display(planningTime);
}

void MainWindow::on_setParameters_NumOfAttempts_PushButton_3_clicked()
{
    int num = ui->setParameters_NumOfAttempts_LineEdit_3->text().toInt();

    //Len test
    ui->status_joint1acc_3->display(num);
}
