#include "ui/MainWindow/HeaderBox.hpp"

HeaderBox::HeaderBox(QWidget * parent):
    QWidget(parent),
    glayout(new QGridLayout()),
    appName(new QLabel()), 
    present_msg(new QLabel())
{
    this->setObjectName("header-box");
    this->setStyleSheet(R"(
            #header-box{
                background-color: white;
                border-radius: 15px;
            }
        )"
    );
    this->setFixedHeight(150);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setLayout(glayout);
    //
    glayout->setObjectName("header-layout");
    glayout->addWidget(appName, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    glayout->addWidget(present_msg, 1, 0, 1, 2, Qt::AlignLeft | Qt::AlignVCenter);
    //
    appName->setObjectName("app-name-label");
    appName->setText("<b style='color:Orange; font-size: 32pt;'>Geny</b>");
    //
    present_msg->setObjectName("present-msg-label");
    present_msg->setText("<b style='color: black; font-size: 16pt;'>Votre generateur de text prefere 😄</b>");
}
