#include "tablemodel.h"
#include <ctime>
Tablemodel::Tablemodel(): sequence(std::time(0))
{

    dialog* dial=new dialog();
    if(dial->exec()==QDialog::Accepted)
    {
        for(int i=0;i<row;i++)
            for(int j=0;j<column;j++)
            {
                listpair.push_back(std::make_pair(i,j));
            }
        min=1;
        if(dial->getlevel()==1)
        {
           max=999;
           time=500;
          Font=5;
        }
        if(dial->getlevel()==2)
        {
           max=500;
           time=1000;
           Font=10;
        }
        if(dial->getlevel()==3)
        {
            max=99;
            time=5000;
            Font=15;
        }

        meaning1=0;meaning2=0;
        flag=false;
        std::uniform_int_distribution<> rand(min*2,max*2);
        sum=rand(sequence);
        timer=new QTimer(this);
        QObject::connect(timer,&QTimer::timeout,this,&Tablemodel::inputview);
        timer->start(time);
    }
    else
    {
        exit(0);
    }

}
int Tablemodel::rowCount(const QModelIndex &rcParent) const
{
  return row;
}

int Tablemodel::columnCount(const QModelIndex &rcParent) const
{
  return column;
}

QVariant Tablemodel::data(
  const QModelIndex &rcIndex, int nRole) const
{
  return datamodel[rcIndex.row()][rcIndex.column()];
}
bool Tablemodel::setData(const QModelIndex &index, const QVariant &value, int nRole)
{
    if(index.isValid())
    {
        QString str= value.toString();
        datamodel[index.row()][index.column()] =str;
        emit dataChanged(index,index);
        return true;
    }
    return false;
}
void Tablemodel::inputview()
{
    std::uniform_int_distribution<> dist(0,listpair.size()-1);
    int n=dist(sequence);
    auto it=listpair.begin();
    for(int i=0;i<n;i++,it++);
    QAbstractItemModel* itmodel=this;
    std::uniform_int_distribution<> rand(min,max);
    auto index=itmodel->index(it->first,it->second);
    itmodel->setData(index,QString("%1").arg(rand(sequence)));
    emit anim_start(it->first,it->second);
    listpair.erase(it);
    if(listpair.empty())
    {
        exit(0);
    }

    timer->start(time);

}
void Tablemodel::onCurrentChanged(int t_row,int t_column)
{

if(datamodel[t_row][t_column].toInt()!=0&&(t_row!=pos_meaning1.first || t_column!=pos_meaning1.second)){
       if(!flag)
       {
           meaning1= datamodel[t_row][t_column].toInt();
pos_meaning1=std::make_pair(t_row,t_column);
emit changemeaning();
flag=true;
       }
       else
       {

           if((datamodel[t_row][t_column].toInt()+meaning1)==sum)
           {   emit anim_end(pos_meaning1.first,pos_meaning1.second);
               emit anim_end(t_row,t_column);
               pos_meaning2=std::make_pair(t_row,t_column);
               meaning1=0;meaning2=0;
               pos_meaning1=std::make_pair(row,column);
               flag=false;
               std::uniform_int_distribution<> rand(min*2,max*2);
               sum=rand(sequence);
                emit changesum();
               emit changemeaning();
               timer2=new QTimer(this);
               QObject::connect(timer2,&QTimer::timeout,this,&Tablemodel::eraseitem);
               timer2->start(150);


           }
           else
           {
               meaning1=0;meaning2=0;
               emit changemeaning();
              pos_meaning1=std::make_pair(row,column);
              flag=false;
           }
       }
   }
}
void Tablemodel::eraseitem()
{

    QAbstractItemModel* itmodel=this;
    listpair.push_back(std::make_pair(pos_meaning1.first,pos_meaning1.second));
    listpair.push_back(std::make_pair(pos_meaning2.first,pos_meaning2.second));
    itmodel->setData(itmodel->index(pos_meaning1.first,pos_meaning1.second),QString(""));
    itmodel->setData(itmodel->index(pos_meaning2.first,pos_meaning2.second),QString(""));

}
