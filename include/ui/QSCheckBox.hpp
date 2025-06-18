#pragma once

#include <QCheckBox>

class QSCheckBox : public QCheckBox{
    Q_OBJECT
public:
    using QCheckBox::QCheckBox;

public slots:
    void nextCheckState() override{
        setChecked(!checkState());
    }
};