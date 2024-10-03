#include "monitor.h"
bool Monitor::AddFile(QString path)
{
    StateFile temp(path);//временный файл для проверки на наличие файла в списке
    if(objects.contains(temp))
    {
        return false;
    }
    objects.push_back(temp);//добавление объекта при его отсутствии в списке
    emit FirstOut(temp.GetFileName(),temp.GetSize(),temp.GetExist());//излучение сигнала на вывод начальной информации о файле
    return true;

}
bool Monitor::DelFile(QString path)//удаление файла
{
    StateFile temp(path);//временный файл для проверки на наличие файла в списке
    if(objects.contains(temp))
    {
        objects.removeOne(temp);
        return true;
    }
    return false;
}

void Monitor::update()//обновление информации о файлах
{
    for(int i=0;i<objects.size();i++)
    {
        StateFile temp = objects[i];// запоминаем прежнюю информацию о файле
        if (objects[i].update())//обновляем информацию и проверяем есть ли изменения
        {
            if (temp.GetExist() && !objects[i].GetExist())// существует => не существует
            {
                emit NotExist(objects[i].GetFileName());
            }
            else if (!temp.GetExist() && objects[i].GetExist())//не существует => существует
            {
                emit Exist(objects[i].GetFileName(),objects[i].GetSize());
            }
            else//изменен раземер
            {
                emit Resized(objects[i].GetFileName(),objects[i].GetSize());
            }
        }
    }

}
