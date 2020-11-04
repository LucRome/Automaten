#pragma once
#include "Node.h"

class Dec_Type : public Node
{
public:
	Dec_Type();

	//delete/hide unused node elements
	void push(Event_Declaration& ed) = delete;
	void push(State_Transitions& st) = delete;
	void push(State& s) = delete;

private:
	using Node::statement_list;
	using Node::state_list;
};

