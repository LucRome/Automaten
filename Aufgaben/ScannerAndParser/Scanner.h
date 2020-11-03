#pragma once
#include <string>
#include <queue>
#include "File.h"
#include "Tokenstruct.h"

class Scanner
{
public:
	Scanner(std::string filepath);
	Token getNextToken(); //old
	Token readNextToken() const; //old
	std::queue<Token> getTokens(); //old
	Token lookup(bool consume);

private:
	Token automat();
	bool scan(); //veraltet -> use lookup()
	int eval(int state); //auﬂer Endstates

	int StandardAlternatives(char c);

	//Zeichenmengen
	bool is_id_start(char c);
	bool is_id_end(char c);
	bool is_fin(char c);


	File m_file;
	std::queue<Token> m_tokens = std::queue<Token>();
	bool m_scanSuccessfull;

	//Hilfe
	bool tokenAlreadyScanned = false;
	Token tempToken;
	std::string m_name = std::string();
};

