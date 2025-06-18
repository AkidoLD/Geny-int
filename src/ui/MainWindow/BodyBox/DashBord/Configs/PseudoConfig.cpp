#include "ui/MainWindow/BodyBox/DashBord/Configs/PseudoConfig.hpp"

PseudoConfig::PseudoConfig(QWidget * parent):
    ConfigBox(parent),
    l_pseudo_label(new QLabel()),
    l_pseudo_spin(new QSpinBox()),
    n_pseudo_label(new QLabel()),
    n_pseudo_spin(new QSpinBox()),
    sample_label(new QLabel()),
    sample_edit(new QLineEdit()),
    r_sample_label(new QLabel()),
    r_sample_check(new QCheckBox())
{
    mode_name->setText("Geny Pseudo");
    //
    l_pseudo_label->setText("Longueur :");
    n_pseudo_label->setText("Nombre :");
    sample_label->setText("Echantillons :");
    r_sample_label->setText("Echantillons Requis :");
    //
    l_pseudo_spin->setMaximum(INT32_MAX);
    n_pseudo_spin->setMaximum(INT32_MAX);
    sample_edit->setMaxLength(50);
    sample_edit->setPlaceholderText("Echantillon ici ...");
    //
    //Row 0
    configs_grid->addWidget(l_pseudo_label, 0, 0, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(l_pseudo_spin, 0, 1, 1, 3);
    //
    configs_grid->addWidget(n_pseudo_label, 0, 4, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(n_pseudo_spin, 0, 5, 1, 3);

    //Row 1
    configs_grid->addWidget(sample_label, 1, 0, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(sample_edit, 1, 1, 1, 3);
    //
    configs_grid->addWidget(r_sample_label, 1, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(r_sample_check, 1, 7, 1, 1, Qt::AlignRight);

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
    //
}