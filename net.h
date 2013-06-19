#ifndef NET_H
#define NET_H
#include<QtNetwork/QHttp>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QUrlInfo>
#include<QObject>
#include<QtNetwork/QNetworkRequest>
#include<QtGui>
#include<QCloseEvent>
class net:public QMainWindow
{
    Q_OBJECT
   public:
    net(QWidget* parent = 0);
    QLabel *lab;
    QPushButton *but,*but1;
    QAction *newaction;

    int replystat(int x= 0);
    void requestFinished ();
    void delay();

  void closeEvent(QCloseEvent* e);

    void allprocess(int,int);
    public slots:
    void stop();
    void preprocess();

    void developer();
   // void wid(QString);

};

#endif // NET_H
