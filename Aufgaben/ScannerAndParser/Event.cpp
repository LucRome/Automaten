#include "Event.h"

Event::Event(std::string name)
	:Dec_Type()
{
	ev_name = name;
	event_list.shrink_to_fit();
	task_list.shrink_to_fit();
	transition_list.shrink_to_fit();
}