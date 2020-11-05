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

const std::vector<std::shared_ptr<Event>>& Transition::getEvents() const
{
	return on_list;
}

const std::vector<std::shared_ptr<Task>>& Transition::getTasks() const
{
	return do_list;
}

const std::shared_ptr<State>& Transition::getState() const
{
	return const_gotoState;
}
