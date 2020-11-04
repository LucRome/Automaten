#include "Node.h"
#include "Event.h"
#include "Task.h"
#include "State.h"
#include "Transition.h"
#include "Event_Declaration.h"
#include "State_Transitions.h"

void Node::push(Event& e)
{
	event_list.push_back(std::make_shared<Event>(e));
}

void Node::push(Task& t)
{
	task_list.push_back(std::make_shared<Task>(t));
}

void Node::push(State& s)
{
	state_list.push_back(std::make_shared<State>(s));
}

void Node::push(Transition& t)
{
	transition_list.push_back(std::make_shared<Transition>(t));
}

void Node::push(Event_Declaration& ed)
{
	statement_list.push_back(std::make_shared<Event_Declaration>(ed));
}

void Node::push(State_Transitions& st)
{
	statement_list.push_back(std::make_shared<State_Transitions>(st));
}

void Node::set_goto(State& s)
{
	gotoState = std::make_shared<State>(s);
}
