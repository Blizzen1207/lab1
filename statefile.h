#ifndef STATEFILE_H
#define STATEFILE_H
#include <QString>
#include <QFileInfo>

class StateFile // класс инфы о файле
{
    QString FileName; // путь до файла
    qint64 size; // размер файла
    bool isExist; // факт существования
public:
    StateFile(); // конструктор по умолчанию
    StateFile(QString path); // коструктор с аргументом QString
    StateFile(const StateFile& temp);//конструктор копирования
    bool operator==(const StateFile& e1) const; // перегрузка оператора сравнения
    bool update(); // функция обновления информации о файле

    //Getters (получить)
    QString GetFileName(); // путь
    qint64 GetSize(); // размер
    bool GetExist(); // факт сущестовования
};
#endif // STATEFILE_H
