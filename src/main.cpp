#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include "ui/MainWindow.hpp"

using namespace std;

int main(int argc, char* argv[]){
    QApplication app (argc, argv);
    MainWindow window;
    window.setWindowTitle("Geny");
    window.resize(720, 940);
    window.show();
    //
    return app.exec();
}