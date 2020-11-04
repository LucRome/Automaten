#pragma once
#include "Statement.h"
#include "Node.h";
#include <vector>
#include <memory>

class FSM : public Node
{
public:
	FSM();

	std::vector<std::shared_ptr<Statement>> statement_list; //children

	//Node deletes
	void push(Event& e) = delete;
	void push(Task& t) = delete;
	void push(State& s) = delete;
	void push(Transition& t) = delete;


//hide objects
private:
	using Node::event_list;
	using Node::task_list;
	using Node::state_list;
	using Node::transition_list;
};