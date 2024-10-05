#ifndef MONITOR_H
#define MONITOR_H

#include "statefile.h"
#include <QObject>
#include <QList>


class Monitor : public QObject // класс наследник qobject т.к работаем с сигналами
{
private:
    Q_OBJECT // для корректной работы механизма сигналов и слотов
    QList<StateFile> objects; // контейнер для файлов

    Monitor(){} // конструктор по умолчанию
    ~Monitor(){} // диструктор
public:
    static Monitor& Instance() // статический метод
    {
        static Monitor s; // статический объект
        return s; // возвращаем ссылку
    }
    bool AddFile(QString path); // добавлениие файла в монитор
    bool DelFile(QString path); // удаление файла из монитора
signals:
    void Resized(QString path, qint64 size); // сигнал если изменился размер
    void Exist(QString path,qint64 size); // сигнал если файл начал существовать
    void NotExist(QString path); // сигнал если файл перестал существовать или не существовал
    void FirstOut(QString path,qint64 size,bool isExist); // сигнал для первого вывода информации о добавленном файле

public slots:
    void update(); // слот для обновления информации о файлах
};

#endif // MONITOR_H
