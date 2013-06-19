#include<QApplication>
#include<net.h>
#include<iostream>
#include<fstream>
using namespace std;
void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int main(int argc , char *argv[])
{
    QApplication a(argc,argv);






    net call ;

    return a.exec();

}
