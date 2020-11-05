#pragma once
#include "Tokenstruct.h"
#include "Scanner.h"
#include "ConsolePrinter.h"
#include "FSM.h"
#include "Node.h"
#include <queue>
#include <stack>
#include <map>

enum nameables{n_task, n_event};

class Parser
{
public:
	Parser(std::string filepath);

	bool parse();
	std::queue<std::string> getCalltimeline() const;
private:
	bool match(Terminals t);
	std::string match_retName(Terminals t); //false =: "", returns name of the token
	bool match_noConsume(Terminals t);

	bool id(std::shared_ptr<Node>& dad, nameables n);
	bool id(std::shared_ptr<State>& self);

	//Produktionen (bekommen 'Vater' (der zugehörigen semantischen Objekte) mitgegeben
	bool FSM_func();
	bool event_declarations(std::shared_ptr<Node>& dad);
	bool id_list(std::shared_ptr<Node>& dad, nameables n);
	bool id_list2(std::shared_ptr<Node>& dad, nameables n);
	bool state_transitions(std::shared_ptr<Node>& dad);
	bool state_transitions2(std::shared_ptr<Node>& dad);
	bool statetransition(std::shared_ptr<Node>& dad);
	bool opt_initial(std::shared_ptr<State>& dad);
	bool transitions(std::shared_ptr<Node>& dad);
	bool transition(std::shared_ptr<Node>& dad);
	bool opt_id_list(std::shared_ptr<Node>& dad);


	Scanner scanner;
	//std::queue<Token> m_tokens;
	std::queue<std::string> m_calltimeline;
	ConsolePrinter printer;


	//TODO: alles in visitor Klasse
	//Symboltabelle: name -> Knoten
	std::map<std::string, std::shared_ptr<Node>&> m_symboltable;

	//AST:
	std::shared_ptr<Node> ast_start;
};

