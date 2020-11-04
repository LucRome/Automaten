#include "State.h"

State::State(std::string name, bool is_initial) 
	:initial(is_initial)
	,state_name(name)
	,Dec_Type()
{
	event_list.shrink_to_fit();
	task_list.shrink_to_fit();
}
