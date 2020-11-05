#pragma once
#include "Node.h"
#include <vector>

class Event_Declaration;
class State;

class FSM :
    public Node
{
public:
    void push(std::shared_ptr<Event_Declaration> ev_dec) override;
    void push(std::shared_ptr<State> state) override;

private:
    std::shared_ptr<Event_Declaration> event_dec = nullptr;
    std::vector<std::shared_ptr<State>> state_list;
};

