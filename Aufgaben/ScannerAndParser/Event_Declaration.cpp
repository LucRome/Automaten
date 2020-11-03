#include "Event_Declaration.h"

void Event_Declaration::push_Event(const Event& ev)
{
	event_list.push_back(std::make_shared<Event>(ev));
}
