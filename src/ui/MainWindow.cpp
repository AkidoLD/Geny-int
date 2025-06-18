#include "ui/MainWindow.hpp"

MainWindow::MainWindow(const QString title, QWidget * parent):
    QMainWindow(parent),
    widget(new QWidget()),
    layout(new QVBoxLayout()),
    headerBox(new HeaderBox()),
    bodyBox(new BodyBox()),
    footerBox(new FooterBox())
{
    this->setObjectName("main-window");
    this->setWindowTitle(title);
    this->resize(650, 720);
    this->setFixedWidth(650);
    this->setMinimumHeight(600);
    this->setCentralWidget(widget);
    this->setContentsMargins(0, 0, 0, 0);
    //
    widget->setObjectName("main-window-widget");
    widget->setLayout(layout);
    //
    layout->setObjectName("main-window-layout");
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(headerBox, 0, Qt::AlignTop);
    layout->addWidget(bodyBox, 1);
    layout->addWidget(footerBox, 0, Qt::AlignBottom);
    //
}
