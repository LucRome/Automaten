#pragma once
#include "Statement.h"
#include "Node.h";
#include <vector>
#include <memory>

class FSM : public Node
{
	void push_statement(std::shared_ptr<Statement> st);
	std::vector<std::shared_ptr<Statement>> statement_list;

	//Node fkts (here: not usable)
private:
	void push(Event& e) override;
	void push(Task& t) override;
	void push(State& s) override;
	void push(Transition& t) override;
};