#include "ui_mainwindow.h"
#include "QWidget"
#include "scara_gui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //QWidget *qWidget = new QWidget();
    QMainWindow *qMain = new QMainWindow();
    Ui::MainWindow mainWindow;
    mainWindow.setupUi(qMain);

    qMain->show();

    return a.exec();
}
