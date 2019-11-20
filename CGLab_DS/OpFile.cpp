#include "OpFile.h"

OpFile::OpFile()
{

}


bool OpFile::dirExist(const string dir_path)
{
	const int ftyp = _access(dir_path.c_str(), 0);
	if (ftyp == 0)
		return true; // 文件夹存在
	else
		return false; // 文件夹不存在
}

string OpFile::formatDirPath(string dir_path)
{
	if (!dirExist(dir_path)) // 此时应该是判断不存在的情况做出相应的处理，现在的处理只是简单的更改为当前目录
	{
		return "./";
	}

	if (dir_path[dir_path.length() - 1] != '\\' && dir_path[dir_path.length() - 1] != '/')
	{
		dir_path += "/";
	}

	return dir_path;
}

