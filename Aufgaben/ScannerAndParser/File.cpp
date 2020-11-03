#include "File.h"
#include <iostream>

File::File(std::string path)
{
	m_file.open(path);
}

void File::closeFile()
{
	m_file.close();
}

char File::getNextChar() //ignores '\n' (Enter
{
	char c;
	do {
		c = m_file.get();
		if (c == '\n') {
			line++;
			column = 0;
		}
		else {
			column++;
		}
	} while (c == '\n');
	return c;
}

char File::peekNextChar() //ignores '\n' (Enter
{
	char c;
	do {
		c = m_file.peek();
	} while (c == '\n');
	return c;
}

void File::ungetChar()
{
	m_file.unget();
}

bool File::fileEnd()
{
	m_file.peek();
	return m_file.eof();
}

int File::getLine() const
{
	return line;
}

int File::getColumn() const
{
	return column;
}
