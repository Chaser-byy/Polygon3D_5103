#include "FileUtil.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::string getFileContent(const std::string& FilePath)
{
	std::ifstream file(FilePath);
	if (!file.is_open())
	{
		std::cout << "ERROR::UTIL::FILE::FAILED_TO_OPEN::" << FilePath << std::endl;
	}
	
	std::stringstream ss;

	ss << file.rdbuf();

	return ss.str();
}