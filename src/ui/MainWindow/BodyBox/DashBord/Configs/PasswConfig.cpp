#include "ui/MainWindow/BodyBox/DashBord/Configs/PasswConfig.hpp"

PasswConfig::PasswConfig(QWidget * parent):
    ConfigBox(parent),
    lenght_label(new QLabel()),
    lenght_spin(new QSpinBox()),
    number_label(new QLabel()),
    number_spin(new QSpinBox())
{
    mode_name->setText("Geny PassWord");
    //
    lenght_label->setText("Longueur : ");
    number_label->setText("Nombre : ");
    //
    number_spin->setMaximum(9999);
    lenght_spin->setMaximum(9999);
    //
    number_spin->setMinimum(1);
    lenght_spin->setMinimum(1);
    //
    number_spin->setValue(10);
    lenght_spin->setValue(10);
    
    //Row 0
    configs_grid->addWidget(lenght_label, 0, 0, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(lenght_spin, 0, 1, 1, 3);
    configs_grid->addWidget(number_label, 0, 4, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(number_spin, 0, 5, 1, 3);
    
    //Row 1
    configs_grid->addWidget(u_char_label, 1, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(u_char_check, 1, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(s_char_label, 1, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(s_char_check, 1, 7, 1, 1, Qt::AlignRight);
    
    //Row 2
    configs_grid->addWidget(l_char_label, 2, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(l_char_check, 2, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(p_char_label, 2, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(p_char_check, 2, 7, 1, 1, Qt::AlignRight);
    
    //Row 3
    configs_grid->addWidget(d_char_label, 3, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(d_char_check, 3, 3, 1, 1, Qt::AlignRight);
    
    //Row 4
    configs_grid->addWidget(homo_gen_label, 4, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(homo_gen_check, 4, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(wdb_char_label, 4, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(wdb_char_check, 4, 7, 1, 1, Qt::AlignRight);

}

