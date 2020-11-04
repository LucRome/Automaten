#include "FSM.h"
#include "Event_Declaration.h"
#include "State_Transitions.h"

FSM::FSM()
{
	event_list.shrink_to_fit();
	task_list.shrink_to_fit();
	state_list.shrink_to_fit();
	transition_list.shrink_to_fit();
}


