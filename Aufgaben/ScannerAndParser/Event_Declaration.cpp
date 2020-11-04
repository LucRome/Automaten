#include "Event_Declaration.h"

Event_Declaration::Event_Declaration()
	:Statement()
{
	state_list.shrink_to_fit();
}
