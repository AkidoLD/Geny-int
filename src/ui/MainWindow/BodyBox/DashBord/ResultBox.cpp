#include "ui/MainWindow/BodyBox/DashBord/ResultBox.hpp"

ResultBox::ResultBox(const QString &result_title_text,QWidget * parent):
    QWidget(parent),
    vlayout(new QVBoxLayout()),
    result_scroll(new QScrollArea()),
    result_list(new QListWidget()),
    result_title(new QLabel())
{
    this->setObjectName("result-box");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setLayout(vlayout);
    //
    vlayout->setObjectName("result-box-layout");
    vlayout->addWidget(result_title, 0, Qt::AlignLeft | Qt::AlignTop);
    vlayout->addWidget(result_scroll, 1);
    //
    result_title->setObjectName("result-box-title");
    result_title->setText(result_title_text);
    //
    result_scroll->setObjectName("result-box-scroll");
    result_scroll->setWidget(result_list);
    result_scroll->setWidgetResizable(true);
    //
    result_list->setObjectName("result-box-list");
    result_list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}