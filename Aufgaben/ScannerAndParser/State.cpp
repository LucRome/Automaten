#include "State.h"

void State::push(std::shared_ptr<Transition> tran)
{
	trans_list.push_back(tran);
}

void State::setInitial(bool isInitial)
{
	initial = isInitial;
}

bool State::getInitial() const
{
	return initial;
}

const std::vector<std::shared_ptr<Transition>>& State::getTransitions() const
{
	return trans_list;
}
