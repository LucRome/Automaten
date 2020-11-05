#include "Event_Declaration.h"

void Event_Declaration::push(std::shared_ptr<Event> ev)
{
	event_list.push_back(ev);
}

const std::vector<std::shared_ptr<Event>>& Event_Declaration::getEvents() const
{
	return event_list;
}
