#pragma once
#include "Dec_Type.h"
#include <vector>
#include <memory>

class Event;
class Task;

class Transition :
    public Dec_Type
{
    Transition();
    void push_OnEvent(Event& ev);
    void push_doTask(Task& t);

    std::vector<std::shared_ptr<Dec_Type>> on_list; //children
    std::vector<std::shared_ptr<Dec_Type>> do_list; //children
};

