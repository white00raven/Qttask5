#include "dialog.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
dialog::dialog(QDialog* parent ):QDialog(parent)
{
     setWindowTitle("Find the amount");
     hardbut=new QRadioButton("Hard :\n time-0.5 seconds font-5 range from 1 to 999 ");
     normbut=new QRadioButton("Normal :\n time-1 seconds font-10 range from 1 to 500 ");
     lowbut=new QRadioButton("Low :\n time-5 seconds font-15 range from 1 to 99 ");
     QGroupBox* group=new QGroupBox();
     QVBoxLayout* vl=new QVBoxLayout();
     vl->addWidget(hardbut);
     vl->addWidget(normbut);
     vl->addWidget(lowbut);
     group->setLayout(vl);
     QPushButton* Ok= new QPushButton("&Ok");
     connect(Ok, SIGNAL(clicked() ),this, SLOT(test() ));
     connect(this,SIGNAL(trueexit()),SLOT(accept()));
     QGridLayout *gr=new QGridLayout();
     gr->addWidget(group,0,0);
     gr->addWidget(Ok,1,0);
     setLayout(gr);

}
void dialog::test()
{

    if(hardbut->isChecked())
    {
       level=1;
       emit trueexit();
    }
    if(normbut->isChecked())
    {
       level=2;
       emit trueexit();
    }
    if(lowbut->isChecked())
    {
       level=3;
       emit trueexit();
    }
}
