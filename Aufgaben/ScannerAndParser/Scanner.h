#pragma once
#include <string>
#include <queue>
#include "File.h"
#include "Tokenstruct.h"

class Scanner
{
public:
	Scanner(std::string filepath);
	Token getNextToken();
	Token readNextToken() const;
	std::queue<Token> getTokens();
	
private:
	bool scan();
	bool scan_nextLexem();
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
	std::string m_name = std::string();
};

