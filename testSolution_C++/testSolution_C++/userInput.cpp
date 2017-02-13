#include "filePath.h"
#include "userInput.h"
#include <iostream>

UserInput::UserInput() : size(0) {}

TypedInput::TypedInput() : UserInput() {}

void TypedInput::setSize()
{
	std::cout << "Type the range of Sum >> ";
	std::cin >> size;
}