#pragma once
#include "Dec_Type.h"
#include <string>
class Event :
    public Dec_Type
{
    Event(std::string name);
    std::string ev_name;
};

