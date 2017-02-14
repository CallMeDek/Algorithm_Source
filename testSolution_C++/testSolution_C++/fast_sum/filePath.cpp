#include "filePath.h"
#include <iostream>
#include <string>

FilePath::FilePath() {}

void FilePath::typeFromUser()
{
	std::cout << "Type the path of file >> ";
	std::cin >> path;
}

std::string FilePath::getPath()
{
	return path;
}