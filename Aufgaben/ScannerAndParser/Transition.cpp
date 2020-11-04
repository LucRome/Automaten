#include "Transition.h"
#include "Event.h"
#include "Task.h"

Transition::Transition()
	:Dec_Type()
{
	transition_list.shrink_to_fit();
}
