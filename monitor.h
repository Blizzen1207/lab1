#ifndef MONITOR_H
#define MONITOR_H

#include "statefile.h"
#include <QObject>
#include <QList>


class Monitor : public QObject//класс наследник qobject т.к работаем с сигналами
{
private:
    Q_OBJECT
    QList<StateFile> objects;

    Monitor(){}
    ~Monitor(){}
    Monitor(Monitor const &);
    Monitor& operator=(Monitor const&);
public:
    static Monitor& Instance()
    {
        static Monitor s;
        return s;
    }
    bool AddFile(QString path);
    bool DelFile(QString path);
signals:
    void Resized(QString path, qint64 size);// сигнал если изменился размер
    void Exist(QString path,qint64 size);//сигнал если файл начал существовать
    void NotExist(QString path);//сигнал если файл перестал существовать или не существовал
    void FirstOut(QString path,qint64 size,bool isExist);//сигнал для первого вывода информации о добавленном файле

public slots:
    void update();//слот для обновления информации о файлах
};

#endif // MONITOR_H
