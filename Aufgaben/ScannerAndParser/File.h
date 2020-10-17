#pragma once
#include <fstream>
#include <string>

class File
{
public:
	File(std::string path);
	void closeFile();
	char getNextChar();
	char peekNextChar();
	void ungetChar();
	bool fileEnd();
private:
	std::ifstream m_file;
};

