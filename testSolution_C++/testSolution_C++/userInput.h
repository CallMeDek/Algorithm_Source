#ifndef USER_INPUT_HEADER
#define USER_INPUT_HEADER

#include "filePath.h"
//#include <iostream>
/*
	There are two type classes which are sub classes of super class "UserInput"
	1. TypedInput - we get the number from User's typing
	2. FiledInput - the number is in one file  
*/

class UserInput {
public: 
	UserInput();
	//void testCode() { std::cout << size << std::endl; };

protected:
	int size;
	virtual void setSize() = 0;
};

class TypedInput : public UserInput {
public:
	TypedInput();
	void setSize();
};

class FiledInput : public UserInput {
public:
	FiledInput();
	void setSize();

private:
	FilePath _path;
	
};

#endif
