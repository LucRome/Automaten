#include "FSM.h"
#include "Event_Declaration.h"
#include "State_Transitions.h"

void FSM::push(Event_Declaration& ed)
{
	statement_list.push_back(std::make_shared<Event_Declaration>(ed));
}

void FSM::push(State_Transitions& st)
{
	statement_list.push_back(std::make_shared<Event_Declaration>(st));
}

FSM::FSM()
{
	event_list.shrink_to_fit();
	task_list.shrink_to_fit();
	state_list.shrink_to_fit();
	transition_list.shrink_to_fit();
}

void FSM::push(Event& e)
{
}

void FSM::push(Task& t)
{
}

void FSM::push(State& s)
{
}

void FSM::push(Transition& t)
{
}


