#ifndef GETHTTPRETURN_H
#define GETHTTPRETURN_H
#include <qprocess.h>
#include <QObject>
#include <qdebug.h>
#include <qlinkedlist.h>
#include <QFile>
#include <QVector>
#include <QThread>
#include "busline.h"
#include "devicesetting.h"
#define GET_BUS_IFOR 1
#define GET_SYS_TIME 2
#define SERVER_IP "http://123.207.75.109:10000/YiYangIndex.ashx?ActionKey="
/*
typedef struct
{
    int id;
    int BF;  // back or forward
    int LSC;  //left stations  2
    char BCNO[20]; //BG4532
    char BRNO[20];//line name  325
    char CD[20];//distance  1800m
    //QString MSG,MSG0;
    //char name[20];
}Bus;
*/

class GetHttpReturn : public QObject
{
    Q_OBJECT
public:
    int p_cmdFlag;
    explicit GetHttpReturn(QObject *parent = 0);
   //QLinkedList <BusLine> lineList,tempList;
    QVector <BusLine> lineList,tempList;
    //QVector<QString> vector(200);
    void GetLines();
    void GetUrl(int cmdFlag);
    void SetDevicePosition();
    void SetSysTime();
    void ClearTemp();
    void CompareInfo();
    void getCOM_buf(BusLine newBus);
    void addActionKey();
    QString strInfor;
    QString strUrl;
    //QString deviceID;
    //QString busFd;
    //QString programVID;
signals:
    void signal_writeCom(const QString &strResult);
public slots:
    //void slot_get_allstatus();
    void slot_requestFinished(bool bSuccess, const QString &strResult);

};

#endif // GETHTTPRETURN_H
