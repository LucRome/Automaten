#include "ConsolePrinter.h"
#include <string>
#include <array>
#include <iostream>

/*schlechter Stil bestimmt*/
std::array<std::string, 12> terminalNames = { "EVENT","IN", "INITIAL", "STATE", "ON", "GOTO", "COMMA",
	"SEMICOLON", "COLON", "ID", "ERROR", "FINISH" };

void ConsolePrinter::printLexeme(std::queue<Token> token)
{
	Token t;
	while (!token.empty()) {
		t = token.front();
		token.pop();
		std::cout << terminalNames[t.type];
		if (t.type == Terminals::ID) {
			std::cout << ": " << t.name;
		}
		std::cout << std::endl;
	}
}

void ConsolePrinter::printParseCalltimeline(std::queue<std::string> timeline)
{
	while (!timeline.empty()) {
		std::cout << timeline.front() << std::endl;
		timeline.pop();
	}
}

void ConsolePrinter::printScannerError(int line, int column)
{
	std::cout << "There was a Scanner Error (symbol not valid) at [line, column]: " << line << "," << column << std::endl;
}

void ConsolePrinter::printParserError(int line, int column, Terminals expected, Token given)
{
	std::cout << "There was a Parser Error (wrong 'word') at [line, column]: " << line << "," << column;
	std::cout << "\nThe expected word was of the type: " << terminalNames[expected] <<  "| given was: " << terminalNames[given.type] << ", " << given.name <<std::endl;
	std::cout << "(ID means any (correct) name declaration" << std::endl;
}
