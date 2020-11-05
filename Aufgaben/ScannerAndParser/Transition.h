#pragma once
#include "Statement.h"
#include <vector>


class Transition :
    public Statement
{
public:
    void push(std::shared_ptr<Event> ev) override;
    void push(std::shared_ptr<Task> ta) override;
    void push(std::shared_ptr<State> st) override;

private:
    std::vector<std::shared_ptr<Event>> on_list;
    std::vector<std::shared_ptr<Task>> do_list;
    std::shared_ptr<State> gotoState = nullptr;
};

