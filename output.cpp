#include "output.h"

void output::outExistFile(QString temp, qint64 size)//вывод на консоль если файл существует
{
    std::cout<< "File "<<temp.toStdString().c_str()<< " exists, size: "<< size<<std::endl;
}
void output::outNonExistFile(QString temp)//вывод на консоль если файл не существует
{
    std::cout<<"File "<< temp.toStdString().c_str()<< " does not exist"<<std::endl;
}
void output::outResizedFile(QString temp, qint64 size)//вывод на консоль если файл изменил размер
{
    std::cout<<"File "<< temp.toStdString().c_str()<<" changed size, new_size: "<<size<<std::endl;
}
void output::FirstOut(QString path, qint64 size, bool isExist)//первый вывод информации о файле
{
    if (isExist)
    {
        std::cout<<"File "<< path.toStdString().c_str()<<" exist, size: " <<size<<std::endl;

    }
    else
    {
        std::cout<<"File "<<path.toStdString().c_str()<<" does not exist"<<std::endl;

    }
}
