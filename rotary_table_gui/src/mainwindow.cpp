#include "../include/rotary_table_gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <pluginlib/class_list_macros.h>
#include <QStringList>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include "ros/ros.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int argc;
    char **argv;
    ros::init(argc, argv, "scara_gui_node");
    ros::NodeHandle n1,n2,n3,n4,nn1,nn2,nn3,nn4;
    ros::Rate loop_rate(10);

    ROS_INFO("spinner for GUI start\n");
    aspinner = new ros::AsyncSpinner(2);
    aspinner->start();

    ROS_WARN("Init publishers:");
    rotate_DEC_pub = n1.advertise<std_msgs::Int32>("rotate_DEC_RT",1000);
    ROS_INFO("rotate_DEC_RT");
    rotate_HEX_pub = n2.advertise<std_msgs::String>("rotate_HEX_RT",1000);
    ROS_INFO("rotate_HEX_RT");
    workingState_pub = n3.advertise<std_msgs::Int32>("set_working_mode_RT",1000);
    ROS_INFO("set_working_mode_RT");
//    rotate_HEX_pub = n4.advertise<std_msgs::Int32>("useless_pub",1000);
//    ROS_INFO("useless_pub_RT");

    ROS_WARN("Init subscribers:");
    currentAngleDeg_sub = nn1.subscribe("currentAngleDeg_RT",1000,&MainWindow::CurrentAngleCallback, this);
    ROS_INFO("currentAngleDeg_RT");
    currentWorkingState_sub = nn2.subscribe("currentWorkingState_RT",1000,&MainWindow::CurrentWorkingStateCallback, this);
    ROS_INFO("currentWorkingState_RT");
    useless_sub = nn3.subscribe("useless_sub_RT",1000,&MainWindow::UselessCallback, this);
    ROS_INFO("useless_sub_RT");

}

MainWindow::~MainWindow()
{
    delete ui;
}

/******************* Config tab *********************/
void MainWindow::on_config_OFF_PB_clicked(){

    ui->status_TE->setTextColor(QColor("orange"));
    ui->status_TE->append("trying to get to state OFF - Check working state");
    sendWorkingMode(1);

}

void MainWindow::on_config_READY_PB_clicked(){

    ui->status_TE->setTextColor(QColor("orange"));
    ui->status_TE->append("trying to get to state READY - Check working state");
    sendWorkingMode(2);

}

void MainWindow::on_config_ON_PB_clicked(){

    ui->status_TE->setTextColor(QColor("orange"));
    ui->status_TE->append("trying to get to state ON - Check working state");
    sendWorkingMode(3);

}

void MainWindow::on_config_ERROR_PB_clicked(){

    ui->status_TE->setTextColor(QColor("orange"));
    ui->status_TE->append("trying to get to state ERROR - Check working state");
    sendWorkingMode(4);

}

/*****************************************************/

/**************** Relative Control *******************/
void MainWindow::on_relativeControl_slider_SLIDER_actionTriggered(int action){

    //GUI
    ui->relativeControl_slider_LE->setText(QString::number(ui->relativeControl_slider_SLIDER->value()) + " deg");

}

void MainWindow::on_relativeControl_slider_PB_clicked(){

    //GUI
   if (directionOfRotation){
        ui->relativeControl_slider_LE->setText(QString::number(ui->relativeControl_slider_SLIDER->value()) + " deg");
        ui->desiredPositionDeg_LCD->display(ui->relativeControl_slider_SLIDER->value() + currentAngleDeg);
        ui->desiredPositionRad_LCD->display((ui->relativeControl_slider_SLIDER->value() + currentAngleDeg) * DEG_TO_RAD);
        currentAngleDeg+=ui->relativeControl_slider_SLIDER->value();
    }else{
        ui->relativeControl_slider_LE->setText(QString::number(-ui->relativeControl_slider_SLIDER->value()) + " deg");
        ui->desiredPositionDeg_LCD->display(-ui->relativeControl_slider_SLIDER->value() + currentAngleDeg);
        ui->desiredPositionRad_LCD->display((-ui->relativeControl_slider_SLIDER->value() + currentAngleDeg) * DEG_TO_RAD);
        currentAngleDeg-=ui->relativeControl_slider_SLIDER->value();
    }
   ui->status_TE->append("Moving[relative] to " + QString::number(ui->relativeControl_slider_SLIDER->value()) + " deg in direction " + QString(directionOfRotation ? "RIGHT":"LEFT"));


}

void MainWindow::on_relativeControl_input_PB_clicked(){

    //GUI
   if (directionOfRotation){
        ui->relativeControl_slider_LE->setText(QString::number(ui->relativeControl_input_LE->text().toDouble()) + " deg");
        ui->desiredPositionDeg_LCD->display(ui->relativeControl_input_LE->text().toDouble() + currentAngleDeg);
        ui->desiredPositionRad_LCD->display((ui->absoluteControl_input_LE->text().toDouble() + currentAngleDeg) * DEG_TO_RAD);
        currentAngleDeg+=ui->relativeControl_input_LE->text().toDouble();
    }else{
        ui->relativeControl_slider_LE->setText(QString::number(-ui->relativeControl_input_LE->text().toDouble()) + " deg");
        ui->desiredPositionDeg_LCD->display(-ui->relativeControl_input_LE->text().toDouble() + currentAngleDeg);
        ui->desiredPositionRad_LCD->display((-ui->absoluteControl_input_LE->text().toDouble() + currentAngleDeg) * DEG_TO_RAD);
        currentAngleDeg-=ui->relativeControl_input_LE->text().toDouble();
    }
    ui->status_TE->append("Moving[relative] to " + QString::number(ui->relativeControl_input_LE->text().toDouble()) + " deg in direction " + QString(directionOfRotation ? "RIGHT":"LEFT"));

}
/*****************************************************/



/**************** Absolute Control ******************/
void MainWindow::on_absoluteControl_slider_SLIDER_actionTriggered(int action){

    //GUI
    ui->absoluteControl_slider_LE->setText(QString::number(ui->absoluteControl_slider_SLIDER->value()) + " deg");

}

void MainWindow::on_absoluteControl_slider_PB_clicked(){

    //GUI
    ui->absoluteControl_slider_LE->setText(QString::number(ui->absoluteControl_slider_SLIDER->value()) + " deg");
    ui->desiredPositionDeg_LCD->display(ui->absoluteControl_slider_SLIDER->value());
    ui->desiredPositionRad_LCD->display(ui->absoluteControl_slider_SLIDER->value()*DEG_TO_RAD);
    ui->status_TE->append("Moving[absolute] to " + QString::number(ui->absoluteControl_slider_SLIDER->value()) + " deg in direction " + QString(directionOfRotation ? "RIGHT":"LEFT"));



}

void MainWindow::on_absoluteControl_input_PB_clicked(){

    //GUI
    ui->absoluteControl_slider_LE->setText(QString::number(ui->absoluteControl_input_LE->text().toDouble()) + " deg");
    ui->desiredPositionDeg_LCD->display(ui->absoluteControl_input_LE->text().toDouble());
    ui->desiredPositionRad_LCD->display(ui->absoluteControl_input_LE->text().toDouble()*DEG_TO_RAD);
    ui->status_TE->append("Moving[absolute] to " + ui->absoluteControl_input_LE->text() + " deg in direction " + QString(directionOfRotation ? "RIGHT":"LEFT"));

}
/*****************************************************/


/******************** Velocity **********************/
void MainWindow::on_MaxVelocity_input_PB_clicked(){

    //GUI
    ui->maxVelocityDeg_LCD->display(ui->MaxVelocity_input_LE->text().toDouble());
    ui->maxVelocityRad_LCD->display(ui->MaxVelocity_input_LE->text().toDouble()*DEG_TO_RAD);
    ui->status_TE->append("Max velocity set to " + ui->MaxVelocity_input_LE->text() + " deg/s");


}
/*****************************************************/


/******************** Direction **********************/
void MainWindow::on_direction_LEFT_PB_clicked(){

    //GUI
    ui->direction_RIGHT_CB->setChecked(false);
    ui->direction_LEFT_CB->setChecked(true);
    ui->direction_LE->setText("Left");

    //ROS
    directionOfRotation = false;

}

void MainWindow::on_direction_RIGHT_PB_clicked(){

    //GUI
    ui->direction_LEFT_CB->setChecked(false);
    ui->direction_RIGHT_CB->setChecked(true);
    ui->direction_LE->setText("Right");

    //ROS
    directionOfRotation = true;
}

void MainWindow::on_direction_LEFT_CB_toggled(bool checked){

    if(checked){
        ui->direction_LE->setText("Left");
        ui->direction_RIGHT_CB->setChecked(false);
        directionOfRotation = false;
    }

}

void MainWindow::on_direction_RIGHT_CB_toggled(bool checked){

    if(checked){
        ui->direction_LE->setText("Right");
        ui->direction_LEFT_CB->setChecked(false);
        directionOfRotation = true;
    }

}
/*****************************************************/


/*********************** STOP ************************/
void MainWindow::on_stop_PB_clicked(){

    //GUI
    ui->status_TE->setTextColor(QColor("red"));
    ui->status_TE->append("Movement STOPPED!");
    ui->status_TE->setTextColor(QColor("black"));

    int hex_size = 9;
    int value = 400;
    char hexValue[20];
    char modifHexValue[hex_size];
    int decValue;
    sprintf(hexValue,"%x",value);
    //printf(hexString, "%X", value);
    ROS_WARN("DEC=%d normal HEX=%s",value,hexValue);
    ROS_INFO("hex size = %d",std::strlen(hexValue));
    ROS_INFO("modif hex size = %d",hex_size);


    for (int i=0;i<hex_size;i++){
        if (i < (hex_size-1) -std::strlen(hexValue)){
            modifHexValue[i] = '0';
        }else{
            modifHexValue[i] = hexValue[i - ((hex_size-1) -std::strlen(hexValue))];
        }
        //getchar();

    }
    modifHexValue[hex_size] = '\0';
    ROS_INFO("modif HEX=%s",modifHexValue);

    //convert from standard format CAN to SENSO format
    char help1,help2;
    for (int i=0;i<hex_size-1-2;i+=4){
        help1= modifHexValue[i];
        help2= modifHexValue[i+1];
        modifHexValue[i] = modifHexValue[i+2];
        modifHexValue[i+1] = modifHexValue[i+3];
        modifHexValue[i+2] = help1;
        modifHexValue[i+3] = help2;
    }
    modifHexValue[hex_size] = '\0';
    ROS_INFO("senso modif HEX=%s",modifHexValue);

    //Convert from SENSO format to standard CAN format
    for (int i=0;i<hex_size-1-2;i+=4){
        help1= modifHexValue[i];
        help2= modifHexValue[i+1];
        modifHexValue[i] = modifHexValue[i+2];
        modifHexValue[i+1] = modifHexValue[i+3];
        modifHexValue[i+2] = help1;
        modifHexValue[i+3] = help2;
    }
    modifHexValue[hex_size] = '\0';
    ROS_INFO("normal format modif HEX=%s",modifHexValue);

    decValue=hex2dec(modifHexValue);
    ROS_WARN("DEC=%d HEX=%s",decValue,modifHexValue);
    //ROS

}

void MainWindow::on_centralStop_PB_clicked(){

    //GUI
    ui->status_TE->setTextColor(QColor("red"));
    ui->status_TE->append("***************************************");
    ui->status_TE->append("CENTRAL STOP -> EXITING PROGRAM!");
    ui->status_TE->append("***************************************");


    //kill roslaunch


    //Kill GUI
    //sleep(3);
    //QApplication::quit();

}
/*****************************************************/



/***************** Custom functons *******************/
void MainWindow::printCurrentWorkingStateOnWidget(const int modeNumber){

    switch (modeNumber){
        case 1: //OFF
        {
            ROS_INFO("State: OFF");
            ui->config_workingState_LE->setText("State: OFF");
            break;
        }
        case 2: //READY
        {
            ROS_INFO("State: READY");
            ui->config_workingState_LE->setText("State: READY");
            break;
        }
        case 3: //ON
        {
            ROS_INFO("State: ON");
            ui->config_workingState_LE->setText("State: ON");
            break;
        }
        case 4: //ERROR
        {
            ROS_INFO("State: ERROR");
            ui->config_workingState_LE->setText("State: ERROR");
            break;
        }
        default:
        {
            ROS_ERROR("Something wrong with state messages ... check connection");
            ui->config_workingState_LE->setText("Something wrong with state messages ... check connection!!!!");
            break;
        }

    }

}

void MainWindow::sendWorkingMode(const int mode){

    //ROS_INFO("Sending choosen mode %d",mode);
    int32_msg.data = mode;
    workingState_pub.publish(int32_msg);

}

int MainWindow::hex2dec(char hex_value[]){

    int length = std::strlen(hex_value);
    int power = 1;
    int dec_value;

    for (int i=length-1;i>=0;i--){

        if (hex_value[i]>='0' && hex_value[i]<='9'){
            dec_value += (hex_value[i] - 48) * power;
            power = power * 16;
        }else if (hex_value[i]>='A' && hex_value[i]<='F'){
            dec_value += (hex_value[i] - 55) * power;
            power = power * 16;
        }
    }

    return dec_value;
}
/*****************************************************/



/******************* Callbacks ***********************/
void MainWindow::CurrentAngleCallback(const std_msgs::Int32 currentAngle){

    //ROS_INFO("Current angle callback %d",currentAngle);



}

void MainWindow::CurrentWorkingStateCallback(const std_msgs::Int32 currentWorkingState){

    //ROS_INFO("Current working state callback %d",currentWorkingState);
    printCurrentWorkingStateOnWidget(currentWorkingState.data);

}

void MainWindow::UselessCallback(const std_msgs::Int32 uselessInfo){

    //ROS_INFO("Useless callback... nothing to show");

}
/*****************************************************/

