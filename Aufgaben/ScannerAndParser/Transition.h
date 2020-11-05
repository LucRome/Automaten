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
    const std::vector<std::shared_ptr<Event>>& getEvents() const;
    const std::vector<std::shared_ptr<Task>>& getTasks() const;
    const std::shared_ptr<State>& getState() const;

private:
    std::vector<std::shared_ptr<Event>> on_list;
    std::vector<std::shared_ptr<Task>> do_list;
    std::shared_ptr<State> gotoState = nullptr;
    const std::shared_ptr<State>& const_gotoState = gotoState;
};

