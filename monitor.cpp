#include "monitor.h"
#include <QDebug>

bool Monitor::AddFile(QString path)
{
    StateFile temp(path); //временный файл для проверки на наличие файла в списке
    if(objects.contains(temp)) // если файл содержится в контейнере
    {
        return false;
    }
    objects.push_back(temp); //добавление объекта при его отсутствии в списке в конец контейнера
    emit FirstOut(temp.GetFileName(),temp.GetSize(),temp.GetExist()); //излучение сигнала на вывод начальной информации о файле
    return true;

}
bool Monitor::DelFile(QString path)//удаление файла
{
    StateFile temp(path); //временный файл для проверки на наличие файла в списке
    if(objects.contains(temp)) // если файл содержится в контейнере
    {
        objects.removeOne(temp); // удаляем с контейнера
        qDebug() << "Deleted file path: " << path; // сообщение об удалении из монитора
        return true;
    }
    return false;
}

void Monitor::update()//обновление информации о файлах
{
    for(int i=0;i<objects.size();i++) // проход по файлам в контейнере
    {
        StateFile temp = objects[i]; // временный объект, где запоминаем прежнюю информацию о файле
        if (objects[i].update()) // если файл был обновлен
        {
            if (temp.GetExist() && !objects[i].GetExist()) // если файл был и его нет после обновления
            {
                emit NotExist(objects[i].GetFileName()); // испускаем сигнал о несуществовании
            }
            else if (!temp.GetExist() && objects[i].GetExist()) // если файла не было и после обновления он есть
            {
                emit Exist(objects[i].GetFileName(),objects[i].GetSize()); // испускаем сигнал о существовании
            }
            else // если изменился размер
            {
                emit Resized(objects[i].GetFileName(),objects[i].GetSize()); // испускаем сигнал о изменении размера
            }
        }
    }

}
