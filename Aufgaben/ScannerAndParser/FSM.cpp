#include "FSM.h"

void FSM::push_statement(std::shared_ptr<Statement> st)
{
	statement_list.push_back(st);
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


