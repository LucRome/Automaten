#include "Scanner.h"
#include <string>
#include <iostream>
#include "ConsolePrinter.h"

int main(std::string args[]) { //Sp�ter: Pfad aus args[]
	std::string path = "Test.txt";
	Scanner scanner = Scanner(path);
	ConsolePrinter printer;
	printer.printLexeme(scanner.getTokens());
}