#include "ui/MainWindow.hpp"

HeaderBox::HeaderBox(QWidget * parent): 
    QWidget(parent),
    layout(new QHBoxLayout(this)),
    name(new QLabel("HeaderBox"))
{
    this->setStyleSheet(R"(
            background-color: blue;
            border-radius: 10px;
        )"
    );
    //
    layout->addWidget(name);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setFixedHeight(150);
}

CenterBox::CenterBox(QWidget * parent):
    QWidget(parent),
    layout(new QHBoxLayout(this)),
    name(new QLabel("CenterBox"))
{
    this->setStyleSheet(R"(
            background-color: yellow;
            border-radius: 10px;
        )"
    );
    //
    layout->addWidget(name);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

LateralBox::LateralBox(QWidget * parent):
    QWidget(parent),
    layout(new QHBoxLayout(this)),
    name(new QLabel)
{
    this->setStyleSheet(R"(
            background-color: red;
            border-radius: 20px;
        )"
    );
    //
    layout->addWidget(name);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedHeight(500);
    this->setFixedWidth(45);
}

MainWindow::MainWindow(QWidget * parent):
    QMainWindow(parent),
    central_widget(new QWidget()),
    central_layout(new QGridLayout()),
    header_widget(new HeaderBox()),
    center_widget(new CenterBox()),
    lateral_widget(new LateralBox())
{
    this->setCentralWidget(central_widget);
    this->setFixedSize(620, 940);
    central_widget->setLayout(central_layout);
    //Ajout des widget des le layout central
    central_layout->addWidget(header_widget, 0, 0, 1, 2);
    central_layout->addWidget(center_widget, 1, 0, 1, 1);
    central_layout->addWidget(lateral_widget, 1, 1, 1, 1, Qt::AlignVCenter);
}
