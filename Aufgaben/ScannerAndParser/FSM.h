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
	void set_goto(State& s) = delete;
	void setName(std::string _name) = delete;
	void setInitial() = delete;


//hide objects
private:
	using Node::event_list;
	using Node::task_list;
	using Node::state_list;
	using Node::transition_list;
	using Node::gotoState;
	using Node::name;
	using Node::initial;
};