#pragma once
#include <queue>
#include <string>
#include "Tokenstruct.h"
#include "TerminalsEnum.h"

class ConsolePrinter
{
public:
	void printLexeme(std::queue<Token> token);
	void printParseCalltimeline(std::queue<std::string> timeline);

	void printScannerError(int line, int column);
	void printParserError(int line, int column, Terminals expected, Token given);
};

