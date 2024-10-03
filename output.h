#ifndef OUTPUT_H
#define OUTPUT_H
#include <QObject>
#include <QTextStream>
#include <iostream>

class output : public QObject//класс наследник qobject т.к. работаем с сигналами-слотами
{
    Q_OBJECT
public slots://слоты для вывода информации
    void outExistFile(QString temp,qint64 size);
    void outNonExistFile(QString temp);
    void outResizedFile(QString temp, qint64 size);
    void FirstOut(QString path, qint64 size,bool isExist);
};

#endif // OUTPUT_H
