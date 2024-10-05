#ifndef OUTPUT_H
#define OUTPUT_H
#include <QObject>
#include <QTextStream>
#include <iostream>

class output : public QObject // класс вывода
{
    Q_OBJECT // для корректной работы механизма сигналов и слотов
public slots://слоты для вывода информации
    void outExistFile(QString temp,qint64 size); // существование файла
    void outNonExistFile(QString temp); // отсутствие файла
    void outResizedFile(QString temp, qint64 size); // изменение размера
    void FirstOut(QString path, qint64 size,bool isExist); // первое обнаружение
};

#endif // OUTPUT_H
