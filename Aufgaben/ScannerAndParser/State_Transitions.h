#pragma once
#include "Statement.h"
#include "Dec_Type.h"
#include "State.h"
#include <memory>
#include <vector>

class State_Transitions :
    public Statement
{
    void push_State(const State& state);
    std::vector<std::shared_ptr<Dec_Type>> state_list;
};

