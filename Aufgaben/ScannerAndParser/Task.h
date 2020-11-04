#pragma once
#include "Dec_Type.h"
#include <string>

class Task :
    public Dec_Type
{
public:
    Task(std::string name);
    std::string task_name;

    //delete/hide unused Dec_Type elements
    void push(Event& e) = delete;
    void push(Task& t) = delete;
    void push(Transition& t) = delete;
    void set_goto(State& s) = delete;

private:
    using Dec_Type::event_list;
    using Dec_Type::task_list;
    using Dec_Type::transition_list;
    using Dec_Type::gotoState;
};

