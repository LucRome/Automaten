#include "State.h"

void State::push(std::shared_ptr<Transition> tran)
{
	trans_list.push_back(tran);
}

bool State::getInitial()
{
	return initial;
}

void State::setInitial(bool isInitial)
{
	initial = isInitial;
}
