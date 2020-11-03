#pragma once
#include "Statement.h"
#include "Dec_Type.h"
#include "Event.h"
#include <vector>
#include <memory>

class Event_Declaration :
    public Statement
{
    void push_Event(const Event& ev);
    std::vector<std::shared_ptr<Dec_Type>> event_list;
};

