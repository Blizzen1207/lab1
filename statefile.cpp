#include "statefile.h"

//Constructors
StateFile::StateFile()//по умолчанию (возможно и не нужен)
{
    FileName = "";
    size = 0;
    isExist = 0;
}
StateFile::StateFile(QString path)
{
    QFileInfo file(path);
    FileName = path;
    size = file.size();
    isExist = file.exists();
}

//Getters
QString StateFile::GetFileName()
{
    return FileName;
}
qint64 StateFile::GetSize()
{
    return size;
}
bool StateFile::GetExist()
{
    return isExist;
}

//update info about file
bool StateFile::update()
{
    QFileInfo temp = QFileInfo(FileName);
    if(temp.exists() && !isExist)//если файл существует, хотя до этого его не было
    {
        isExist = true;
        size = temp.size();
        return true;
    }
    else if(!temp.exists() && isExist)//если файл не существует, хотя до этого существовал
    {
        isExist = false;
        size = 0;
        return true;
    }
    else if(temp.size()!= size)//если файл изменил свой размер
    {
        size = temp.size();
        return true;
    }
    return false;
}


//overload == and = functions
bool StateFile::operator==(const StateFile& e1) const
{
    return e1.FileName == FileName && e1.size == size && e1.isExist == isExist;
}
StateFile& StateFile::operator =(const StateFile& temp)
{
    FileName = temp.FileName;
    isExist = temp.isExist;
    size = temp.size;
    return *this;

}
// copy constructor
StateFile::StateFile(const StateFile& temp)
{
    FileName = temp.FileName;
    isExist = temp.isExist;
    size = temp.size;

}
