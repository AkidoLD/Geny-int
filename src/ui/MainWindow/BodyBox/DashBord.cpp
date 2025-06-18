#include "ui/MainWindow/BodyBox/DashBord.hpp"

DashBord::DashBord(QWidget * parent):
    QWidget(parent),
    glayout(new QGridLayout()),
    pswConfig(new PasswConfig())
{
    this->setObjectName("dashbord");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setLayout(glayout);
    //  
    glayout->setObjectName("dashbord-layout");
    glayout->addWidget(new PasswConfig(), 0, 0, Qt::AlignTop);
    glayout->addWidget(new UidConfig(), 1, 0, Qt::AlignTop);
    glayout->addWidget(new PseudoConfig(), 2, 0, Qt::AlignTop);
    //
}