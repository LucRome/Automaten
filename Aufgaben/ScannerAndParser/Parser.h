#pragma once
#include "Tokenstruct.h"
#include "Scanner.h"
#include "ConsolePrinter.h"
#include "FSM.h"
#include <queue>

class Parser
{
public:
	Parser(std::string filepath);

	bool parse();
	std::queue<std::string> getCalltimeline() const;
private:
	bool match(Terminals t);
	bool match_noConsume(Terminals t);

	//Produktionen
	bool FSM_func();
	bool event_declarations();
	bool id_list();
	bool id_list2();
	bool state_transitions();
	bool state_transitions2();
	bool statetransition();
	bool opt_initial();
	bool transitions();
	bool transition();
	bool opt_id_list();

	Scanner scanner;
	//std::queue<Token> m_tokens;
	std::queue<std::string> m_calltimeline;
	ConsolePrinter printer;

	//AST:
	FSM& ast_start;
};

