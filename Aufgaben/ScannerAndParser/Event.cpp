#include "Event.h"

Event::Event()
	:Dec_Type()
{
	event_list.shrink_to_fit();
	task_list.shrink_to_fit();
	transition_list.shrink_to_fit();
}