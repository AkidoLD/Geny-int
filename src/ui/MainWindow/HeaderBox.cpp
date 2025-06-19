#include "ui/MainWindow/HeaderBox.hpp"

HeaderBox::HeaderBox(QWidget * parent):
    QWidget(parent),
    glayout(new QGridLayout()),
    appName(new QLabel()), 
    present_msg(new QLabel())
{
    this->setObjectName("header-box");
    this->setStyleSheet(w_style);
    this->setFixedHeight(175);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setLayout(glayout);
    //
    glayout->setObjectName("header-layout");
    glayout->addWidget(appName, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignBottom);
    glayout->addWidget(present_msg, 1, 0, 1, 2, Qt::AlignLeft | Qt::AlignVCenter);
    //
    appName->setObjectName("app-name-label");
    appName->setText("Geny");
    //
    present_msg->setObjectName("present-msg-label");
    present_msg->setText("Votre generateur de text prefere 😄");
}

const QString HeaderBox::w_style{R"(
        #header-box{
            background-color: #FFD500;
            border-radius: 15px;
            border: 3px solid white;
        }

        #header-box #app-name-label{
            color: #FFFF00;
            font-size: 54pt;
            font-weight: 1000;
            font-family: 'DejaVu Serif', monospace;
            margin-left: 2px;
            margin-top: 10px
        }
        #header-box #present-msg-label{
            color: black;
            font-size: 17pt;
            font-weight: 600;
            font-family: 'DejaVu Serif', monospace;
            margin-left: 80px;
        }
    )"
};
