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
	void set_goto(State& s) = delete;
	void setName(std::string _name) = delete;
	void setInitial() = delete;
	
private:
	using Node::statement_list;
	using Node::task_list;
	using Node::transition_list;
	using Node::gotoState;
	using Node::name;
	using Node::initial;
};

