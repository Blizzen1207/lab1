#include <QCoreApplication>
#include "monitor.h"
#include "output.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Monitor& eye = Monitor::Instance();
    output out;
    QObject::connect(&eye,&Monitor::Resized,&out,&output::outResizedFile);
    QObject::connect(&eye,&Monitor::Exist,&out,&output::outExistFile);
    QObject::connect(&eye,&Monitor::NotExist,&out,&output::outNonExistFile);
    QObject::connect(&eye,&Monitor::FirstOut,&out,&output::FirstOut);
    eye.AddFile("C:\\Primer\\qt.txt");//добавляем файлы под наблюдение
    eye.AddFile("C:\\Primer\\123.txt");
    eye.AddFile("C:\\Primer\\file3.txt");
    eye.AddFile("C:\\Primer\\file.txt");

    QTimer* timer = new QTimer(&eye);//добавление таймера и связи м/д сигналом и слотом
    QObject::connect(timer,SIGNAL(timeout()),&eye,SLOT(update()));
    timer->start(100);
    return a.exec();
}
