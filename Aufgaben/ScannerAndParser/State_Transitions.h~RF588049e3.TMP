#pragma once
#include "Statement.h"
#include "Dec_Type.h"
#include "State.h"
#include <memory>
#include <vector>

class State_Transitions :
    public Statement
{
    State_Transitions();

    //delete/hide unused Statement elements
    void push(Event& e) = delete;

private:
    using Statement::event_list;
};

