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
    this->resize(620, 720);
    this->setFixedWidth(620);
    this->setMinimumHeight(480);
    this->setCentralWidget(widget);
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
