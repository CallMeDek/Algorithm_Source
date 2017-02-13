#include "filePath.h"
#include "userInput.h"
#include <iostream>
#include <fstream>

UserInput::UserInput() : size(0) {}

TypedInput::TypedInput() : UserInput() {}

void TypedInput::setSize()
{
	std::cout << "Type the range of Sum >> ";
	std::cin >> size;
}

FiledInput::FiledInput() : UserInput() {}

void FiledInput::setSize()
{
	//Make an object of "FilePath" class and get file's path
	_path.typeFromUser();
	std::string my_path = _path.getPath();
	
	//Create an inputStream with file's path we just have got
	std::ifstream inputStream(my_path);
	std::string temp;

	//Type casting from string to int
	getline(inputStream, temp);
	size = atoi(temp.c_str());

	inputStream.close();
}