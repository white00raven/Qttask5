#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QRadioButton>

class dialog:public QDialog
{

    Q_OBJECT
    QRadioButton* hardbut,*normbut,*lowbut;
    int level;
public:
    int getlevel(){return level;}
    dialog(QDialog *parent = nullptr);
signals:
    void trueexit();
public slots:
    void test();
};

#endif // DIALOG_H
