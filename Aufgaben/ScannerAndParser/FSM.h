#pragma once
#include "Statement.h"
#include <vector>
#include <memory>

class FSM
{
	void push_statement(std::shared_ptr<Statement> st);
	std::vector<std::shared_ptr<Statement>> statement_list;
};

