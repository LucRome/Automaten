#pragma once
#include <queue>
#include "Tokenstruct.h"

class ConsolePrinter
{
public:
	void printLexeme(std::queue<Token> token);
};

