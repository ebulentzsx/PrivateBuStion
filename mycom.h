#ifndef MYCOM_H
#define MYCOM_H
#include <QtCore>
#include <QObject>
 #include <QMutex>
#include "qextserialbase.h"
#include "posix_qextserialport.h"
#include "readcomthread.h"
#include "devicesetting.h"
#include <QCoreApplication>
#include <QTimer>
#include "pubulicDefine.h"

class myCOM : public QObject
{
    Q_OBJECT
public:
    explicit myCOM(QObject *parent = 0);
    readComThread *readThread;
    Posix_QextSerialPort *myCom;
    QString strTime;
    bool flag_isOpen;
    static  bool writeState;

    QMutex writeLock;
    static int waitCount;
  //  myCOM();
    void setCOM();//Setting
    int openCOM();//Open COM and create new thread
    int sendCOM(QByteArray buf);
    int recvCOM();
    int testCOM();
    void closeCOM();
    //void addTask();
   // void RemoveTask();
    void getCurrentTime();
    void run();
signals:
    void signal_getErrorMsg(int code, const QString &strResult);
    void signal_getState(QByteArray strResult);
    void signal_COM_error(bool com_state);
public slots:
    void slot_getStateFromCom(const QString &tmp);
    void slot_send_COM(QByteArray buf);
    void slot_re_open_COM(bool com_state);
    void slot_init();
 //   void slot_return_timeout();
};

#endif // MYCOM_H
