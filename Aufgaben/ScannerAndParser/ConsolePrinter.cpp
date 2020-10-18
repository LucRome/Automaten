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
