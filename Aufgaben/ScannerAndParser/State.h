#pragma once
#include "Named.h"
#include <vector>

class State :
    public Named
{
public:
    void push(std::shared_ptr<Transition> tran) override;
    void setInitial(bool isInitial);
    bool getInitial() const;
    const std::vector<std::shared_ptr<Transition>>& getTransitions() const;

private:
    bool initial = false;
    std::vector<std::shared_ptr<Transition>> trans_list;
};

