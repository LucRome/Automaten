#include "State.h"

State::State() 
	:Dec_Type()
{
	event_list.shrink_to_fit();
	task_list.shrink_to_fit();
}
