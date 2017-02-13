#ifndef FILE_PATH_HEADER
#define FIEL_PATH_HEADER

#include <string>
/*
	If the input of user is from text file, 
	we will use this object for presenting file's path.
*/

class FilePath {
public:
	FilePath();

	// User will type the file's path in this function
	void typeFromUser();

	std::string getPath();
private:
	std::string path;
};

#endif
