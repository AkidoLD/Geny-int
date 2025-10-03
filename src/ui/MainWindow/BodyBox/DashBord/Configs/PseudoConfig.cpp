#include "ui/MainWindow/BodyBox/DashBord/Configs/PseudoConfig.hpp"

PseudoConfig::PseudoConfig(QWidget * parent):
    ConfigBox(parent),
    l_pseudo_max_label(new QSLabel()),
    l_pseudo_max_spin(new QSpinBox()),
    l_pseudo_min_label(new QSLabel()),
    l_pseudo_min_spin(new QSpinBox()),
    n_pseudo_label(new QSLabel()),
    n_pseudo_spin(new QSpinBox()),
    sample_label(new QSLabel()),
    sample_edit(new QLineEdit()),
    r_sample_label(new QSLabel()),
    r_sample_check(new QSCheckBox())
{
    mode_name->setText("Geny Pseudo");
    //
    l_pseudo_max_label->setText("Longueur Max :");
    l_pseudo_min_label->setText("Longueur Min :");
    n_pseudo_label->setText("Nombre :");
    sample_label->setText("Echantillons :");
    r_sample_label->setText("Echantillons Requis :");
    //
    l_pseudo_max_spin->setMaximum(9999);
    l_pseudo_min_spin->setMaximum(9999);
    n_pseudo_spin->setMaximum(1000);
    sample_edit->setMaxLength(50);
    sample_edit->setPlaceholderText("Echantillon ici...");
    
    //Default values
    l_pseudo_max_spin->setValue(10);
    l_pseudo_min_spin->setValue(10);
    n_pseudo_spin->setValue(10);
    sample_edit->setText("");
    
    //Row 0
    configs_grid->addWidget(l_pseudo_max_label, 0, 0, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(l_pseudo_max_spin, 0, 1, 1, 3);
    //
    configs_grid->addWidget(n_pseudo_label, 0, 4, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(n_pseudo_spin, 0, 5, 1, 3);

    //Row 1
    configs_grid->addWidget(l_pseudo_min_label, 1, 0, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(l_pseudo_min_spin, 1, 1, 1, 3);
    //
    configs_grid->addWidget(sample_label, 1, 4, 1, 1, Qt::AlignLeft);
    configs_grid->addWidget(sample_edit, 1, 5, 1, 3, Qt::AlignRight);

    //Row 2
    configs_grid->addWidget(wdb_char_label, 2, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(wdb_char_check, 2, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(r_sample_label, 2, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(r_sample_check, 2, 7, 1, 1, Qt::AlignRight);

    //Row 3
    configs_grid->addWidget(u_char_label, 3, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(u_char_check, 3, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(d_char_label, 3, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(d_char_check, 3, 7, 1, 1, Qt::AlignRight);

    //Row 4
    configs_grid->addWidget(l_char_label, 4, 0, 1, 3,Qt::AlignLeft);
    configs_grid->addWidget(l_char_check, 4, 3, 1, 1,Qt::AlignRight);
    //
    configs_grid->addWidget(s_char_label, 4, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(s_char_check, 4, 7, 1, 1, Qt::AlignRight);

    //Row 5
    configs_grid->addWidget(homo_gen_label, 5, 0, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(homo_gen_check, 5, 3, 1, 1, Qt::AlignRight);
    //
    configs_grid->addWidget(p_char_label, 5, 4, 1, 3, Qt::AlignLeft);
    configs_grid->addWidget(p_char_check, 5, 7, 1, 1, Qt::AlignRight);
    //
    connect_label_to_check(r_sample_label,r_sample_check);

    //Connection des signaux de verification
    QObject::connect(l_pseudo_max_spin, &QSpinBox::valueChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(l_pseudo_min_spin, &QSpinBox::valueChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(n_pseudo_spin, &QSpinBox::valueChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(sample_edit, &QLineEdit::textChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(r_sample_check, &QSCheckBox::stateChanged, [&](){
        emit config_change(this);
    });

}