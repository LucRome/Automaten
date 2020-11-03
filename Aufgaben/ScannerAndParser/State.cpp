#include "State.h"

State::State(std::string name, bool is_initial) 
	:initial(is_initial)
	,state_name(name)
{
}

void State::push_Transition(const Transition& tran)
{
	transition_list.push_back(std::make_shared<Transition>(tran));
}
