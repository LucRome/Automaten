#include "Scanner.h"
#include <string>
#include <iostream>
#include "ConsolePrinter.h"
#include "Parser.h"

int main(std::string args[]) { //Später: Pfad aus args[]
	std::string path = "Test.txt";
	Scanner scanner = Scanner(path);
	ConsolePrinter printer;
	printer.printLexeme(scanner.getTokens());
	Parser parser = Parser(scanner.getTokens());
	std::cout << parser.parse() << std::endl;
	printer.printParseCalltimeline(parser.getCalltimeline());
}