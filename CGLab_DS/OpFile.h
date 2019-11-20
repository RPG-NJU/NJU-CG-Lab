#ifndef OPFILE_H
#define OPFILE_H

#include <string>
#include <io.h>

using std::string;


class OpFile
{
public:
    OpFile();
	static bool dirExist(const string dir_path);
	static string formatDirPath(string dir_path);
};

#endif // OPFILE_H
