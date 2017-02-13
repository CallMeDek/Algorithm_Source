#ifndef USER_INPUT_HEADER
#define USER_INPUT_HEADER

/*
	There are two type classes which are sub classes of super class "UserInput"
	1. TypedInput - we get the number from User's typing
	2. FiledInput - the number is in one file  
*/

class UserInput {
public: 
	UserInput();
protected:
	int size;
	void setSize();
};

class TypedInput : public UserInput {
public:
	TypedInput();
};

class FiledInput : public UserInput {
public:
	FiledInput();
};

#endif
