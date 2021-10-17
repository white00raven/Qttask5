#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QString>
#include <QAbstractTableModel>
#include <QTimer>
#include <list>
#include <random>
#include "dialog.h"
class Tablemodel :public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY( int meaning1 READ getmeaning  NOTIFY changemeaning)
    Q_PROPERTY (int sum READ getsum  NOTIFY changesum)
    Q_PROPERTY( int Font READ getFont NOTIFY changefont)
private:
    int max,min,sum,meaning1,Font,time;
    int row=20,column=20;
    QString datamodel[20][20];
    bool flag;
    std::mt19937 sequence;
    std::pair<int,int> pos_meaning1,pos_meaning2;
    QTimer* timer,*timer2;
    std::list<std::pair<int,int>> listpair;

public:
    Tablemodel();
    virtual int rowCount(const QModelIndex &rcParent)const;
    virtual int columnCount(const QModelIndex &rcParent) const;
    virtual QVariant data(const QModelIndex &rcIndex, int nRole) const;
    virtual bool setData(const QModelIndex & index,const QVariant & value,int nRole=0);
    int getsum(){return sum;}
    int getFont(){return Font;}
    int getmeaning(){return meaning1;}
    Q_INVOKABLE
    void onCurrentChanged(int row,int column);

    signals:
     void changesum();
     void changemeaning();
     void anim_start(int t_row,int t_column);
     void anim_end(int t_row,int t_column);
     void changefont();

     private slots:
     void inputview();
     void eraseitem();

};
#endif // TABLEMODEL_H
