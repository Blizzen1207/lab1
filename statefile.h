#ifndef STATEFILE_H
#define STATEFILE_H
#include <QString>
#include <QFileInfo>

class StateFile
{
    QString FileName;//путь до файла
    qint64 size;//размер файла
    bool isExist;//флаг существования
public:
    StateFile();//конструктор по умолчанию
    StateFile(QString path);//коструктор с аргументом QString
    bool operator==(const StateFile& e1) const;//перегрузка оператора сравнения
    bool update();//функция обновления информации о файле
    //Getters
    QString GetFileName();
    qint64 GetSize();
    bool GetExist();
public:
    StateFile(const StateFile& temp);//конструктор копирования
    StateFile& operator =(const StateFile& temp);//перегрузка оператора присваивания


};
#endif // STATEFILE_H
