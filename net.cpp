#include<QProcess>
#include<QDebug>
#include<QObject>
#include<QWidget>
#include<QString>
#include<iostream>
#include<QApplication>
#include<process.h>
#include<QFile>
#include<fstream>
#include<QDebug>
#include<QtNetwork/QHttp>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QUrlInfo>
#include<QDataStream>
#include<QEventLoop>

#include<QtNetwork/QNetworkReply>
#include<net.h>
#include<QCoreApplication>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkCookieJar>
#include<QTime>
#include<QTextStream>
#include<QFile>
#include<QMainWindow>
using namespace std;
int static j=90;
int static t=1;

 net::net(QWidget *parent):QMainWindow(parent)
{
     QWidget *widget = new QWidget;

     QMenu *menu;


     menu = menuBar()->addMenu( tr("&About") );
      newaction = new QAction("Developer",this);
      menu->addAction(newaction);
     connect(newaction,SIGNAL(triggered()),this,SLOT(developer()));

     lab = new QLabel;
     lab->setText("<font color= red>See Status Here </font>");
     but = new QPushButton("Terminate");
       but1 = new QPushButton("Start");
     but->setFixedSize(80,30);
     but1->setFixedSize(80,30);
     QHBoxLayout *lay = new QHBoxLayout;
     lay->addWidget(but1);

     lay->addWidget(but);
     lay->addWidget(lab);
     widget->setLayout(lay);
    this->setWindowTitle("Ion Trolled 7th Block"); //setWindowIconText("Rajat");
     //widget->setWindowTitle("Rajat Trolled Ion");
     this->setCentralWidget(widget);
     this->setStyleSheet("*{background-color:rgb(202,200,  200)}");
     this->setWindowOpacity(.9);
     this->show();
     connect(but, SIGNAL(clicked()),this,SLOT(stop()));
     connect(but1, SIGNAL(clicked()),this,SLOT(preprocess()));


 }
void net::preprocess()
{
    but1->setEnabled(0);
    allprocess(0,0);
}

 void net::allprocess(int u,int v)

 {

     QString path = QCoreApplication::applicationDirPath();



     if(v==0)
     {
         lab->setText("<font color = green>Please Wait . . .</font>");
         ofstream foot,fvbs0;





         foot.open("k.bat");

         QString str1 = "@echo off\n netsh interface ip set dns \"Wireless Network Connection\" static 10.49.0.45";

         char *ch1= str1.toLocal8Bit().data();
         foot.write(ch1,str1.length());
          foot.close();

         fvbs0.open("k.vbs");
         QString strvbs0 = "Set WshShell = CreateObject(\"WScript.Shell\")\nWshShell.Run chr(34) & \""+path+"/k.bat\" & Chr(34), 0\nSet WshShell = Nothing";
         char *chvbs0= strvbs0.toLocal8Bit().data();
         fvbs0.write(chvbs0,strvbs0.length());
         qDebug()<<chvbs0;
         fvbs0.close();


        QProcess myprocess1;

        QString script1 = "cscript";
            QStringList args1;
            args1<<QString(QDir::currentPath()+ "/k.vbs");
            myprocess1.start(script1,args1);

            delay();

           myprocess1.start(script1,args1);

     }



     ofstream fout,fvbs,fping,fvbsping;
     QString str,strvbs,strping,strvbsping;


     qDebug()<<u;

          if(j<255)
           { if(u==1)
               exit(0);
             else
              {
                 ++j;
                 fout.open("l.bat");
                 str = "@echo off\nnetsh interface ip set address name=\"Wireless Network Connection\" static 10.67.0."+ QString::number(j)+ " 255.255.255.0 10.67.0.1\n";
                 char *ch= str.toLocal8Bit().data();
                 fout.write(ch,str.length());
                 qDebug()<<ch;
                 fout.close();

                 fvbs.open("l.vbs");
                 strvbs = "Set WshShell = CreateObject(\"WScript.Shell\")\nWshShell.Run chr(34) & \""+path+"/l.bat\" & Chr(34), 0\nSet WshShell = Nothing";
                 char *chvbs= strvbs.toLocal8Bit().data();
                 fvbs.write(chvbs,strvbs.length());
                 qDebug()<<chvbs;

                 fvbs.close();


                 fping.open("p.bat");
                 strping = "@echo off\nping google.com>ion.txt";
                 char *chping= strping.toLocal8Bit().data();
                 fping.write(chping,strping.length());
                 fping.close();
                 qDebug()<<chping;


                 fvbsping.open("p.vbs");
                 strvbsping = "Set WshShell = CreateObject(\"WScript.Shell\")\nWshShell.Run chr(34) & \""+path+"/p.bat\" & Chr(34), 0\nSet WshShell = Nothing";
                 char *chvbsping= strvbsping.toLocal8Bit().data();
                 fvbsping.write(chvbsping,strvbsping.length());
                 fvbsping.close();
                 qDebug()<<chvbsping;

                 QProcess myprocess;

                 QString script = "cscript";
                     QStringList args;
                     args<<QString(QDir::currentPath()+ "/l.vbs");
                     myprocess.start(script,args);

                 delay();


                 lab->setText("<b><font color = blue>Attempt No. : </font></b>"+ QString::number(t));

                 ++t;

                 QProcess process2;
                 QString sscript = "cscript";
                     QStringList argss;
                     argss<<QString(QDir::currentPath()+ "/p.vbs");
                     process2.start(sscript,argss);


                 delay();



                 qDebug()<<"system call made";

                 requestFinished();
                 }

          }


 }

void net::delay()
 {
     QTime dieTime= QTime::currentTime().addSecs(4);
     while( QTime::currentTime() < dieTime )
     QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
 }

void net::requestFinished()
{
    qDebug()<<"in RequestFInished";
    QFile file("ion.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Text);

    QTextStream in(&file);
    QString line = in.readAll();
    qDebug()<<line;

    if(line.contains("Reply"))

       {
        lab->setText("<b>CONNECTED !!</b><br><b>Here it is</b></br><br><b>Enjoy The World Of INTERNET</b> ");

        for(;;)
            delay();

          file.close();
          qDebug()<<"yes";
          replystat(1);
       }
    else
    {lab->setText("<b><font color = green>Checking For Connectivity . . . .</font></b>");

          file.close();
          delay();
          replystat(0);
       }

}


int net::replystat(int x)
 {
        qDebug()<<"in return";
        allprocess(x,1) ;

        return 0;
 }
void net::stop()
{
    exit(0);
}
void net::developer()
{


   QWidget *devel = new QWidget;
   QLabel *lab = new QLabel;

   lab->setText("<p><b>Developed By:</b><br><b> RAJAT GUPTA</b><br><b>MIT Manipal</b><br>""<br><b>rajatgupta431@gmail.com</b><br><b><font color=\"white\">www.facebook.com/LUGManipal</font></b></p>");

   QVBoxLayout lay;

   lay.addWidget(lab);
   devel->setLayout(&lay);
   devel->setStyleSheet("*{background-color:rgb(10,125,	200	)}");
   devel->setWindowTitle("LUG Manipal");
   devel->show();

}
void net::closeEvent(QCloseEvent *e)
{
    exit(0) ;
}
