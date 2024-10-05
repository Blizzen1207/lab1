#include "statefile.h"

StateFile::StateFile() // конструктор по умолчанию
{
    FileName = "";
    size = 0;
    isExist = false;
}

StateFile::StateFile(QString path) // конструктор с параметром
{
    //инициализация
    QFileInfo file(path); // объекта file
    FileName = path; // пути
    size = file.size(); // размера
    isExist = file.exists(); // факта существования
}

//Getters (получить)
QString StateFile::GetFileName() // путь
{
    return FileName;
}
qint64 StateFile::GetSize() // размер
{
    return size;
}
bool StateFile::GetExist() // факт существования
{
    return isExist;
}

bool StateFile::update() // объявление информации о файле
{
    QFileInfo temp = QFileInfo(FileName); // получаем информацию о файле
    if(temp.exists() && !isExist) // если файл существует и его не было до
    {
        isExist = true;
        size = temp.size();
        return true;
    }
    else if(!temp.exists() && isExist) // если файл не существует и он был до
    {
        isExist = false;
        size = 0;
        return true;
    }
    else if(temp.size()!= size)// если изменился размер
    {
        size = temp.size();
        return true;
    }
    return false; // обновление инфы о файле не требуется
}

bool StateFile::operator==(const StateFile& e1) const // оператор сравнения
{
    return e1.FileName == FileName && e1.size == size && e1.isExist == isExist;
}

StateFile::StateFile(const StateFile& temp) // конструктор копирования
{
    FileName = temp.FileName;
    isExist = temp.isExist;
    size = temp.size;

}
