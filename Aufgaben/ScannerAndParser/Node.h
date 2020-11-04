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
	virtual void push(Event& e);
	virtual void push(Task& t);
	virtual void push(State& s);
	virtual void push(Transition& t);
	virtual void push(Event_Declaration& ed);
	virtual void push(State_Transitions& st);

	/*potential children, delete unneccessary*/
	std::vector<std::shared_ptr<Statement>> statement_list;
	std::vector<std::shared_ptr<Dec_Type>> event_list;
	std::vector<std::shared_ptr<Dec_Type>> task_list;
	std::vector<std::shared_ptr<Dec_Type>> state_list;
	std::vector<std::shared_ptr<Dec_Type>> transition_list;
};

