/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTabWidget *control_Tabwidget;
    QWidget *tab_1;
    QLabel *label_98;
    QLabel *label;
    QLabel *label_9;
    QWidget *tab_2;
    QLabel *label_28;
    QFrame *frame_8;
    QPushButton *config_OFF_PB;
    QPushButton *config_READY_PB;
    QPushButton *config_ON_PB;
    QPushButton *config_ERROR_PB;
    QFrame *frame_9;
    QWidget *horizontalLayoutWidget_18;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_26;
    QLineEdit *config_workingState_LE;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSlider *relativeControl_slider_SLIDER;
    QLineEdit *relativeControl_slider_LE;
    QPushButton *relativeControl_slider_PB;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *relativeControl_input_LE;
    QPushButton *relativeControl_input_PB;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QSlider *absoluteControl_slider_SLIDER;
    QLineEdit *absoluteControl_slider_LE;
    QPushButton *absoluteControl_slider_PB;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *absoluteControl_input_LE;
    QPushButton *absoluteControl_input_PB;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *MaxVelocity_input_LE;
    QPushButton *MaxVelocity_input_PB;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_16;
    QCheckBox *direction_LEFT_CB;
    QPushButton *direction_LEFT_PB;
    QPushButton *direction_RIGHT_PB;
    QCheckBox *direction_RIGHT_CB;
    QTabWidget *positionAndStatus_TabWidget;
    QWidget *tab_11;
    QFrame *frame;
    QLabel *label_10;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QLabel *label_11;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLCDNumber *desiredPositionDeg_LCD;
    QLCDNumber *desiredPositionRad_LCD;
    QFrame *frame_3;
    QLabel *label_19;
    QWidget *horizontalLayoutWidget_12;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *horizontalLayoutWidget_13;
    QHBoxLayout *horizontalLayout_13;
    QLCDNumber *maxVelocityDeg_LCD;
    QLCDNumber *maxVelocityRad_LCD;
    QFrame *frame_4;
    QLabel *label_22;
    QWidget *horizontalLayoutWidget_14;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_23;
    QLabel *label_24;
    QWidget *horizontalLayoutWidget_15;
    QHBoxLayout *horizontalLayout_15;
    QLCDNumber *currentVelocityDeg_LCD;
    QLCDNumber *currentVelocityRad_LCD;
    QFrame *frame_2;
    QLabel *label_16;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_11;
    QLCDNumber *currentPositionDeg_LCD;
    QLCDNumber *currentPositionRad_LCD;
    QFrame *frame_5;
    QWidget *horizontalLayoutWidget_17;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_27;
    QLineEdit *direction_LE;
    QWidget *tab_21;
    QLabel *label_2;
    QPushButton *stop_PB;
    QPushButton *centralStop_PB;
    QFrame *frame_6;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_29;
    QTextEdit *status_TE;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(817, 910);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 0, 361, 51));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 180, 121, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(490, 180, 241, 31));
        control_Tabwidget = new QTabWidget(centralWidget);
        control_Tabwidget->setObjectName(QStringLiteral("control_Tabwidget"));
        control_Tabwidget->setGeometry(QRect(50, 210, 391, 511));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        label_98 = new QLabel(tab_1);
        label_98->setObjectName(QStringLiteral("label_98"));
        label_98->setGeometry(QRect(20, 10, 341, 431));
        label = new QLabel(tab_1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 291, 151));
        label->setPixmap(QPixmap(QString::fromUtf8("../IMG_20171006_175133_preview.jpeg")));
        label->setScaledContents(true);
        label_9 = new QLabel(tab_1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(90, 220, 191, 151));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../IMG_20171006_175125_preview.jpeg")));
        label_9->setScaledContents(true);
        control_Tabwidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_28 = new QLabel(tab_2);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(10, 10, 361, 231));
        label_28->setPixmap(QPixmap(QString::fromUtf8("../Screenshot from 2017-10-11 16-52-30.png")));
        label_28->setScaledContents(true);
        frame_8 = new QFrame(tab_2);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setGeometry(QRect(10, 250, 361, 131));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        config_OFF_PB = new QPushButton(frame_8);
        config_OFF_PB->setObjectName(QStringLiteral("config_OFF_PB"));
        config_OFF_PB->setGeometry(QRect(10, 10, 161, 51));
        config_READY_PB = new QPushButton(frame_8);
        config_READY_PB->setObjectName(QStringLiteral("config_READY_PB"));
        config_READY_PB->setGeometry(QRect(190, 10, 161, 51));
        config_ON_PB = new QPushButton(frame_8);
        config_ON_PB->setObjectName(QStringLiteral("config_ON_PB"));
        config_ON_PB->setGeometry(QRect(10, 70, 161, 51));
        config_ERROR_PB = new QPushButton(frame_8);
        config_ERROR_PB->setObjectName(QStringLiteral("config_ERROR_PB"));
        config_ERROR_PB->setGeometry(QRect(190, 70, 161, 51));
        frame_9 = new QFrame(tab_2);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setGeometry(QRect(10, 380, 361, 81));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_18 = new QWidget(frame_9);
        horizontalLayoutWidget_18->setObjectName(QStringLiteral("horizontalLayoutWidget_18"));
        horizontalLayoutWidget_18->setGeometry(QRect(0, 0, 361, 80));
        horizontalLayout_18 = new QHBoxLayout(horizontalLayoutWidget_18);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_26 = new QLabel(horizontalLayoutWidget_18);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_18->addWidget(label_26);

        config_workingState_LE = new QLineEdit(horizontalLayoutWidget_18);
        config_workingState_LE->setObjectName(QStringLiteral("config_workingState_LE"));

        horizontalLayout_18->addWidget(config_workingState_LE);

        control_Tabwidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayoutWidget = new QWidget(tab_3);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 352, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        relativeControl_slider_SLIDER = new QSlider(verticalLayoutWidget);
        relativeControl_slider_SLIDER->setObjectName(QStringLiteral("relativeControl_slider_SLIDER"));
        relativeControl_slider_SLIDER->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(relativeControl_slider_SLIDER);

        relativeControl_slider_LE = new QLineEdit(verticalLayoutWidget);
        relativeControl_slider_LE->setObjectName(QStringLiteral("relativeControl_slider_LE"));

        horizontalLayout->addWidget(relativeControl_slider_LE);

        relativeControl_slider_PB = new QPushButton(verticalLayoutWidget);
        relativeControl_slider_PB->setObjectName(QStringLiteral("relativeControl_slider_PB"));

        horizontalLayout->addWidget(relativeControl_slider_PB);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        relativeControl_input_LE = new QLineEdit(verticalLayoutWidget);
        relativeControl_input_LE->setObjectName(QStringLiteral("relativeControl_input_LE"));

        horizontalLayout_2->addWidget(relativeControl_input_LE);

        relativeControl_input_PB = new QPushButton(verticalLayoutWidget);
        relativeControl_input_PB->setObjectName(QStringLiteral("relativeControl_input_PB"));

        horizontalLayout_2->addWidget(relativeControl_input_PB);


        verticalLayout->addLayout(horizontalLayout_2);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        absoluteControl_slider_SLIDER = new QSlider(verticalLayoutWidget);
        absoluteControl_slider_SLIDER->setObjectName(QStringLiteral("absoluteControl_slider_SLIDER"));
        absoluteControl_slider_SLIDER->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(absoluteControl_slider_SLIDER);

        absoluteControl_slider_LE = new QLineEdit(verticalLayoutWidget);
        absoluteControl_slider_LE->setObjectName(QStringLiteral("absoluteControl_slider_LE"));

        horizontalLayout_3->addWidget(absoluteControl_slider_LE);

        absoluteControl_slider_PB = new QPushButton(verticalLayoutWidget);
        absoluteControl_slider_PB->setObjectName(QStringLiteral("absoluteControl_slider_PB"));

        horizontalLayout_3->addWidget(absoluteControl_slider_PB);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        absoluteControl_input_LE = new QLineEdit(verticalLayoutWidget);
        absoluteControl_input_LE->setObjectName(QStringLiteral("absoluteControl_input_LE"));

        horizontalLayout_4->addWidget(absoluteControl_input_LE);

        absoluteControl_input_PB = new QPushButton(verticalLayoutWidget);
        absoluteControl_input_PB->setObjectName(QStringLiteral("absoluteControl_input_PB"));

        horizontalLayout_4->addWidget(absoluteControl_input_PB);


        verticalLayout->addLayout(horizontalLayout_4);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        MaxVelocity_input_LE = new QLineEdit(verticalLayoutWidget);
        MaxVelocity_input_LE->setObjectName(QStringLiteral("MaxVelocity_input_LE"));

        horizontalLayout_5->addWidget(MaxVelocity_input_LE);

        MaxVelocity_input_PB = new QPushButton(verticalLayoutWidget);
        MaxVelocity_input_PB->setObjectName(QStringLiteral("MaxVelocity_input_PB"));

        horizontalLayout_5->addWidget(MaxVelocity_input_PB);


        verticalLayout->addLayout(horizontalLayout_5);

        label_25 = new QLabel(verticalLayoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label_25);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        direction_LEFT_CB = new QCheckBox(verticalLayoutWidget);
        direction_LEFT_CB->setObjectName(QStringLiteral("direction_LEFT_CB"));

        horizontalLayout_16->addWidget(direction_LEFT_CB, 0, Qt::AlignHCenter);

        direction_LEFT_PB = new QPushButton(verticalLayoutWidget);
        direction_LEFT_PB->setObjectName(QStringLiteral("direction_LEFT_PB"));

        horizontalLayout_16->addWidget(direction_LEFT_PB);

        direction_RIGHT_PB = new QPushButton(verticalLayoutWidget);
        direction_RIGHT_PB->setObjectName(QStringLiteral("direction_RIGHT_PB"));

        horizontalLayout_16->addWidget(direction_RIGHT_PB);

        direction_RIGHT_CB = new QCheckBox(verticalLayoutWidget);
        direction_RIGHT_CB->setObjectName(QStringLiteral("direction_RIGHT_CB"));

        horizontalLayout_16->addWidget(direction_RIGHT_CB, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(horizontalLayout_16);

        control_Tabwidget->addTab(tab_3, QString());
        positionAndStatus_TabWidget = new QTabWidget(centralWidget);
        positionAndStatus_TabWidget->setObjectName(QStringLiteral("positionAndStatus_TabWidget"));
        positionAndStatus_TabWidget->setGeometry(QRect(470, 210, 331, 511));
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        frame = new QFrame(tab_11);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 20, 311, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 10, 161, 16));
        horizontalLayoutWidget_6 = new QWidget(frame);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(0, 30, 311, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(horizontalLayoutWidget_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_6->addWidget(label_12);

        label_11 = new QLabel(horizontalLayoutWidget_6);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_6->addWidget(label_11);

        horizontalLayoutWidget_7 = new QWidget(frame);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(0, 60, 311, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        desiredPositionDeg_LCD = new QLCDNumber(horizontalLayoutWidget_7);
        desiredPositionDeg_LCD->setObjectName(QStringLiteral("desiredPositionDeg_LCD"));

        horizontalLayout_7->addWidget(desiredPositionDeg_LCD);

        desiredPositionRad_LCD = new QLCDNumber(horizontalLayoutWidget_7);
        desiredPositionRad_LCD->setObjectName(QStringLiteral("desiredPositionRad_LCD"));

        horizontalLayout_7->addWidget(desiredPositionRad_LCD);

        frame_3 = new QFrame(tab_11);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 200, 311, 101));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_19 = new QLabel(frame_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(50, 6, 201, 20));
        horizontalLayoutWidget_12 = new QWidget(frame_3);
        horizontalLayoutWidget_12->setObjectName(QStringLiteral("horizontalLayoutWidget_12"));
        horizontalLayoutWidget_12->setGeometry(QRect(0, 30, 311, 31));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_12);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(horizontalLayoutWidget_12);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_12->addWidget(label_20);

        label_21 = new QLabel(horizontalLayoutWidget_12);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_12->addWidget(label_21);

        horizontalLayoutWidget_13 = new QWidget(frame_3);
        horizontalLayoutWidget_13->setObjectName(QStringLiteral("horizontalLayoutWidget_13"));
        horizontalLayoutWidget_13->setGeometry(QRect(0, 60, 311, 31));
        horizontalLayout_13 = new QHBoxLayout(horizontalLayoutWidget_13);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        maxVelocityDeg_LCD = new QLCDNumber(horizontalLayoutWidget_13);
        maxVelocityDeg_LCD->setObjectName(QStringLiteral("maxVelocityDeg_LCD"));

        horizontalLayout_13->addWidget(maxVelocityDeg_LCD);

        maxVelocityRad_LCD = new QLCDNumber(horizontalLayoutWidget_13);
        maxVelocityRad_LCD->setObjectName(QStringLiteral("maxVelocityRad_LCD"));

        horizontalLayout_13->addWidget(maxVelocityRad_LCD);

        frame_4 = new QFrame(tab_11);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(10, 300, 311, 111));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_22 = new QLabel(frame_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(70, 5, 161, 21));
        horizontalLayoutWidget_14 = new QWidget(frame_4);
        horizontalLayoutWidget_14->setObjectName(QStringLiteral("horizontalLayoutWidget_14"));
        horizontalLayoutWidget_14->setGeometry(QRect(0, 30, 311, 31));
        horizontalLayout_14 = new QHBoxLayout(horizontalLayoutWidget_14);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(horizontalLayoutWidget_14);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_14->addWidget(label_23);

        label_24 = new QLabel(horizontalLayoutWidget_14);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_14->addWidget(label_24);

        horizontalLayoutWidget_15 = new QWidget(frame_4);
        horizontalLayoutWidget_15->setObjectName(QStringLiteral("horizontalLayoutWidget_15"));
        horizontalLayoutWidget_15->setGeometry(QRect(0, 60, 311, 31));
        horizontalLayout_15 = new QHBoxLayout(horizontalLayoutWidget_15);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        currentVelocityDeg_LCD = new QLCDNumber(horizontalLayoutWidget_15);
        currentVelocityDeg_LCD->setObjectName(QStringLiteral("currentVelocityDeg_LCD"));

        horizontalLayout_15->addWidget(currentVelocityDeg_LCD);

        currentVelocityRad_LCD = new QLCDNumber(horizontalLayoutWidget_15);
        currentVelocityRad_LCD->setObjectName(QStringLiteral("currentVelocityRad_LCD"));

        horizontalLayout_15->addWidget(currentVelocityRad_LCD);

        frame_2 = new QFrame(tab_11);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 110, 311, 91));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(70, 10, 161, 16));
        horizontalLayoutWidget_10 = new QWidget(frame_2);
        horizontalLayoutWidget_10->setObjectName(QStringLiteral("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(0, 30, 311, 31));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(horizontalLayoutWidget_10);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_10->addWidget(label_17);

        label_18 = new QLabel(horizontalLayoutWidget_10);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_10->addWidget(label_18);

        horizontalLayoutWidget_11 = new QWidget(frame_2);
        horizontalLayoutWidget_11->setObjectName(QStringLiteral("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(0, 60, 311, 31));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        currentPositionDeg_LCD = new QLCDNumber(horizontalLayoutWidget_11);
        currentPositionDeg_LCD->setObjectName(QStringLiteral("currentPositionDeg_LCD"));

        horizontalLayout_11->addWidget(currentPositionDeg_LCD);

        currentPositionRad_LCD = new QLCDNumber(horizontalLayoutWidget_11);
        currentPositionRad_LCD->setObjectName(QStringLiteral("currentPositionRad_LCD"));

        horizontalLayout_11->addWidget(currentPositionRad_LCD);

        frame_5 = new QFrame(tab_11);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(10, 400, 321, 81));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_17 = new QWidget(frame_5);
        horizontalLayoutWidget_17->setObjectName(QStringLiteral("horizontalLayoutWidget_17"));
        horizontalLayoutWidget_17->setGeometry(QRect(0, 10, 311, 61));
        horizontalLayout_17 = new QHBoxLayout(horizontalLayoutWidget_17);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(horizontalLayoutWidget_17);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_17->addWidget(label_27);

        direction_LE = new QLineEdit(horizontalLayoutWidget_17);
        direction_LE->setObjectName(QStringLiteral("direction_LE"));

        horizontalLayout_17->addWidget(direction_LE);

        positionAndStatus_TabWidget->addTab(tab_11, QString());
        tab_21 = new QWidget();
        tab_21->setObjectName(QStringLiteral("tab_21"));
        positionAndStatus_TabWidget->addTab(tab_21, QString());
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 771, 121));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../Sensodrive-LogoE.gif")));
        label_2->setScaledContents(true);
        stop_PB = new QPushButton(centralWidget);
        stop_PB->setObjectName(QStringLiteral("stop_PB"));
        stop_PB->setGeometry(QRect(20, 730, 161, 121));
        centralStop_PB = new QPushButton(centralWidget);
        centralStop_PB->setObjectName(QStringLiteral("centralStop_PB"));
        centralStop_PB->setGeometry(QRect(200, 730, 251, 121));
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(470, 730, 331, 121));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_4 = new QWidget(frame_6);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 331, 121));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_29 = new QLabel(verticalLayoutWidget_4);
        label_29->setObjectName(QStringLiteral("label_29"));

        verticalLayout_4->addWidget(label_29);

        status_TE = new QTextEdit(verticalLayoutWidget_4);
        status_TE->setObjectName(QStringLiteral("status_TE"));

        verticalLayout_4->addWidget(status_TE);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 817, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        control_Tabwidget->setCurrentIndex(1);
        positionAndStatus_TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">Rotary table GUI</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Control</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Position and Status</span></p></body></html>", 0));
        label_98->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Wellcome to ROTARY TABLE<br/>Graphical User Interface</span></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><span style=\" font-size:10pt; font-weight:600; font-style:italic;\">This GUI was provided by SENSODRIVE </span></p><p><span style=\" font-size:10pt; font-weight:600; font-style:italic;\">and Viktor Dluhos</span></p><p><br/></p></body></html>", 0));
        label->setText(QString());
        label_9->setText(QString());
        control_Tabwidget->setTabText(control_Tabwidget->indexOf(tab_1), QApplication::translate("MainWindow", "     Info      ", 0));
        label_28->setText(QString());
        config_OFF_PB->setText(QApplication::translate("MainWindow", "OFF", 0));
        config_READY_PB->setText(QApplication::translate("MainWindow", "READY", 0));
        config_ON_PB->setText(QApplication::translate("MainWindow", "ON", 0));
        config_ERROR_PB->setText(QApplication::translate("MainWindow", "ERROR", 0));
        label_26->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Working state</span></p></body></html>", 0));
        control_Tabwidget->setTabText(control_Tabwidget->indexOf(tab_2), QApplication::translate("MainWindow", "  Configuration ", 0));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Relative position control</span></p></body></html>", 0));
        relativeControl_slider_PB->setText(QApplication::translate("MainWindow", "PushButton", 0));
        relativeControl_input_PB->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Absolute position control</span></p></body></html>", 0));
        absoluteControl_slider_PB->setText(QApplication::translate("MainWindow", "PushButton", 0));
        absoluteControl_input_PB->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Edit max velocity</span></p></body></html>", 0));
        MaxVelocity_input_PB->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_25->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Edit direction of rotation</span></p></body></html>", 0));
        direction_LEFT_CB->setText(QString());
        direction_LEFT_PB->setText(QApplication::translate("MainWindow", "<- LEFT", 0));
        direction_RIGHT_PB->setText(QApplication::translate("MainWindow", "RIGHT ->", 0));
        direction_RIGHT_CB->setText(QString());
        control_Tabwidget->setTabText(control_Tabwidget->indexOf(tab_3), QApplication::translate("MainWindow", "     Position control    ", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Desired position</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Position [deg]</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Position [rad]</span></p></body></html>", 0));
        label_19->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Max enabled velocity</span></p></body></html>", 0));
        label_20->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Position [deg/s]</span></p></body></html>", 0));
        label_21->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Position [rad/s]</span></p></body></html>", 0));
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Current velocity</span></p></body></html>", 0));
        label_23->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Position [deg]</span></p></body></html>", 0));
        label_24->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Position [rad]</span></p></body></html>", 0));
        label_16->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Current position</span></p></body></html>", 0));
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Position [deg]</span></p></body></html>", 0));
        label_18->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Position [rad]</span></p></body></html>", 0));
        label_27->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Direction</span></p></body></html>", 0));
        positionAndStatus_TabWidget->setTabText(positionAndStatus_TabWidget->indexOf(tab_11), QApplication::translate("MainWindow", "                Position         ", 0));
        positionAndStatus_TabWidget->setTabText(positionAndStatus_TabWidget->indexOf(tab_21), QApplication::translate("MainWindow", "             Status             ", 0));
        label_2->setText(QString());
        stop_PB->setText(QApplication::translate("MainWindow", "STOP", 0));
        centralStop_PB->setText(QApplication::translate("MainWindow", "CENTRAL STOP and EXIT", 0));
        label_29->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Status</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
