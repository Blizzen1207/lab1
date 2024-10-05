#include <QCoreApplication>
#include "monitor.h"
#include "output.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Monitor& monit = Monitor::Instance(); // создаем объект мониторинга
    output display; // создаем объект вывода
    // соединение сигналов монитора и слотов вывода
    QObject::connect(&monit,&Monitor::Resized,&display,&output::outResizedFile);
    QObject::connect(&monit,&Monitor::Exist,&display,&output::outExistFile);
    QObject::connect(&monit,&Monitor::NotExist,&display,&output::outNonExistFile);
    QObject::connect(&monit,&Monitor::FirstOut,&display,&output::FirstOut);
    // добавляем файлы под наблюдение
    monit.AddFile("C:\\Primer\\qt.txt");
    monit.AddFile("C:\\Primer\\123.txt");
    monit.AddFile("C:\\Primer\\file3.txt");
    monit.AddFile("C:\\Primer\\file.txt");
    // удаляем файлы из наблюдения
    //monit.DelFile("C:\\Primer\\qt.txt");

    QTimer* timer = new QTimer(&monit);//добавление таймера и связи м/д сигналом и слотом
    QObject::connect(timer,SIGNAL(timeout()),&monit,SLOT(update()));
    timer->start(100);
    return a.exec();
}
