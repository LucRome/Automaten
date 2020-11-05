#include "Scanner.h"
#include <string>
#include <iostream>
#include "ConsolePrinter.h"
#include "Parser.h"

int main(std::string args[]) { //Später: Pfad aus args[]
	std::string path = "Test.txt";
	ConsolePrinter printer;
	Parser parser = Parser(path);
	std::cout << parser.parse() << std::endl;
	printer.printParseCalltimeline(parser.getCalltimeline());
}