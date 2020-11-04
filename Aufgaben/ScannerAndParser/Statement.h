#pragma once
#include "Node.h"

class Statement : public Node
{
public:
	Statement();

	//delete unused elements of Node
	void push(Task& t) = delete;
	void push(Transition& t) = delete;
	void push(Event_Declaration& ed) = delete;
	void push(State_Transitions& st) = delete;
	
private:
	using Node::statement_list;
	using Node::task_list;
	using Node::transition_list;
};

