#include "State.h"

State::State(std::string name) 
	:Dec_Type()
{
	setName(name);
	event_list.shrink_to_fit();
	task_list.shrink_to_fit();
}
