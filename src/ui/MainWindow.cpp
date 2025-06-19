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
    this->setStyleSheet(w_style);
    //
    widget->setObjectName("main-window-widget");
    widget->setLayout(layout);
    //
    layout->setObjectName("main-window-layout");
    layout->setContentsMargins(10, 10 ,10 ,10);
    layout->addWidget(headerBox, 0, Qt::AlignTop);
    layout->addWidget(bodyBox, 1);
    layout->addWidget(footerBox, 0, Qt::AlignBottom);
    //
}

const QString MainWindow::w_style{R"(
        #main-window{
            background-color: white;
        }

        #main-window-widget{
            background-color: #FFFF99;
            border-radius: 15px;
            border: 3px solid rgb(143, 143, 143);
            margin: 3px;
        }
        
        #main-window QLabel{
            color: black;
        }
        
    )"
};
