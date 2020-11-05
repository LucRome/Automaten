#include "FSM.h"

void FSM::push(std::shared_ptr<Event_Declaration> ev_dec)
{
	event_dec = ev_dec;
}

void FSM::push(std::shared_ptr<State> state)
{
	state_list.push_back(state);
}
