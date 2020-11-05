#include "Transition.h"

void Transition::push(std::shared_ptr<Event> ev)
{
	on_list.push_back(ev);
}

void Transition::push(std::shared_ptr<Task> ta)
{
	do_list.push_back(ta);
}

void Transition::push(std::shared_ptr<State> st)
{
	gotoState = st;
}
