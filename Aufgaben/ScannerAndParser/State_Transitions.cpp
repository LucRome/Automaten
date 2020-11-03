#include "State_Transitions.h"

void State_Transitions::push_State(const State& state)
{
	state_list.push_back(std::make_shared<State>(state));
}
