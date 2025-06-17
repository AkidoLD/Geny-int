#include "ui/MainWindow/BodyBox/ModeBox.hpp"

ModeBox::ModeBox(QWidget * parent):
    QWidget(parent),
    vlayout(new QVBoxLayout()),
    mode_widget(new QWidget()),
    mode_layout(new QVBoxLayout())
{
    this->setObjectName("mode-box");
    this->setFixedWidth(45);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    this->setLayout(vlayout);
    //
    vlayout->setObjectName("mode-box-layout");
    vlayout->addWidget(mode_widget, 0, Qt::AlignVCenter);
    //
    mode_widget->setObjectName("mode-box-widget");
    mode_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    mode_widget->setLayout(mode_layout);
    //
    mode_layout->setObjectName("mode-box-widget-layout");
    mode_layout->setSpacing(3);
    mode_layout->setAlignment(Qt::AlignVCenter);
    //
}