#pragma once
#include "Dec_Type.h"
#include "Transition.h"
#include <string>
#include <vector>
#include <memory>

class State :
    public Dec_Type
{
    State(std::string name, bool is_initial);
    void push_Transition(const Transition& tran);

    bool initial;
    std::string state_name;
    std::vector<std::shared_ptr<Dec_Type>> transition_list;
};

