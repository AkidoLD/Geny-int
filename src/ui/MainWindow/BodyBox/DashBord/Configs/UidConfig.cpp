#include "ui/MainWindow/BodyBox/DashBord/Configs/UidConfig.hpp"

UidConfig::UidConfig(QWidget * parent):
    ConfigBox(parent),
    n_bloc_label(new QLabel()),
    n_bloc_spin(new QSpinBox()),
    l_bloc_label(new QLabel()),
    l_bloc_spin(new QSpinBox()),
    n_uid_label(new QLabel()),
    n_uid_spin(new QSpinBox()),
    s_bloc_label(new QLabel()),
    s_bloc_edit(new QLineEdit())
{
    mode_name->setText("Geny UID");
    //
    n_bloc_label->setText("Nombre de bloc :");
    l_bloc_label->setText("Longueur d'un bloc :");
    s_bloc_label->setText("Separateur de bloc :");
    n_uid_label->setText("Nombre de generation :");
    //
    n_bloc_spin->setMaximum(100);
    l_bloc_spin->setMaximum(100);
    s_bloc_edit->setMaxLength(10);
    s_bloc_edit->setPlaceholderText("Separateur ici...");
    n_uid_spin->setMaximum(1000);

    //Default values
    n_bloc_spin->setValue(4);
    l_bloc_spin->setValue(4);
    n_uid_spin->setValue(10);
    s_bloc_edit->setText("-");
    //Row 0
    configs_grid->addWidget(n_bloc_label, 0, 0, 1, 1);
    configs_grid->addWidget(n_bloc_spin, 0, 1, 1, 3);
    //
    configs_grid->addWidget(l_bloc_label, 0, 4, 1, 1);
    configs_grid->addWidget(l_bloc_spin, 0, 5, 1, 3);

    //Row 1
    configs_grid->addWidget(s_bloc_label, 1, 0, 1, 1);
    configs_grid->addWidget(s_bloc_edit, 1, 1, 1, 3);
    //
    configs_grid->addWidget(n_uid_label, 1, 4, 1, 1);
    configs_grid->addWidget(n_uid_spin, 1, 5, 1, 3);

    //Row 2
    configs_grid->addWidget(u_char_label, 2, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(u_char_check, 2, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(s_char_label, 2, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(s_char_check, 2, 7, 1, 1, Qt::AlignRight);

    //Row 3
    configs_grid->addWidget(l_char_label, 3, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(l_char_check, 3, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(p_char_label, 3, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(p_char_check, 3, 7, 1, 1, Qt::AlignRight);

    //Row 4
    configs_grid->addWidget(d_char_label, 4, 0, 1, 3,Qt::AlignLeft);
    configs_grid->addWidget(d_char_check, 4, 3, 1, 1,Qt::AlignRight);

    //Row 5
    configs_grid->addWidget(homo_gen_label, 5, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(homo_gen_check, 5, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(wdb_char_label, 5, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(wdb_char_check, 5, 7, 1, 1, Qt::AlignRight);
    
    //Connection des signaux de verification
    QObject::connect(n_bloc_spin, &QSpinBox::valueChanged, [&](){
        emit config_change(this);
    });

    QObject::connect(l_bloc_spin, &QSpinBox::valueChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(n_uid_spin, &QSpinBox::valueChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(s_bloc_edit, &QLineEdit::textChanged, [&](){
        emit config_change(this);
    });

}