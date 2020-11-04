#pragma once
#include <vector>
#include <memory>

class Event;
class Task;
class State;
class Transition;
class Event_Declaration;
class State_Transitions;
class Dec_Type;
class Statement;

class Node
{
public:
	void push(Event& e);
	void push(Task& t);
	void push(State& s);
	void push(Transition& t);
	void push(Event_Declaration& ed);
	void push(State_Transitions& st);
	void set_goto(State& s);

	/*potential children, delete unneccessary*/
	std::vector<std::shared_ptr<Statement>> statement_list;
	std::vector<std::shared_ptr<Dec_Type>> event_list;
	std::vector<std::shared_ptr<Dec_Type>> task_list;
	std::vector<std::shared_ptr<Dec_Type>> state_list;
	std::vector<std::shared_ptr<Dec_Type>> transition_list;
	std::shared_ptr<Dec_Type> gotoState;
};

