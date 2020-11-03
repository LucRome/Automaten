#include "Transition.h"
#include "Event.h"
#include "Task.h"

void Transition::push_OnEvent(Event& ev)
{
	on_list.push_back(std::make_shared<Event>(ev));
}

void Transition::push_doTask(Task& t)
{
	do_list.push_back(std::make_shared<Task>(t));
}
