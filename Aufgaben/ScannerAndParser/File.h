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

	int getLine() const;
	int getColumn() const;

private:
	int line = 0;
	int column = 0;
	std::ifstream m_file;
};

