#pragma once
#include "Named.h"
#include <vector>

class State :
    public Named
{
public:
    void push(std::shared_ptr<Transition> tran) override;
    bool getInitial();
    void setInitial(bool isInitial);

private:
    bool initial = false;
    std::vector<std::shared_ptr<Transition>> trans_list;
};

