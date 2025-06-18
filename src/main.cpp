#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include "ui/MainWindow.hpp"
#include "controls/AppControls.hpp"
#include "model/GenyRand.hpp"

using namespace std;

int main(int argc, char* argv[]){
    QApplication app (argc, argv);
    GenyRand genyModel("/home/akido-ld/Documents/Memo/Guide pour Github et Git.txt");
    MainWindow genyView("Geny-int");
    //
    AppControls genyControl(&genyView, &genyModel);
    genyView.setWindowTitle("Geny");
    genyView.resize(720, 940);
    genyView.show();
    //
    return app.exec();
}