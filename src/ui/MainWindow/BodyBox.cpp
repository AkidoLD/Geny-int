#include "ui/MainWindow/BodyBox.hpp"

BodyBox::BodyBox(QWidget * parent):
    QWidget(parent),
    vlayout(new QVBoxLayout()),
    menu_stack(new QStackedWidget()),
    dashBord(new DashBord())
{
    this->setObjectName("body-box");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setLayout(vlayout);
    this->setContentsMargins(0, 0, 0, 0);
    //
    vlayout->setObjectName("body-box-layout");
    vlayout->addWidget(menu_stack);
    vlayout->setContentsMargins(0, 0, 0, 0);
    //
    menu_stack->setObjectName("body-box-menu-stack");
    menu_stack->addWidget(dashBord);
    menu_stack->setCurrentWidget(dashBord);
}