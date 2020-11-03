#pragma once
#include "Dec_Type.h"
#include <string>

class Task :
    public Dec_Type
{
    Task(std::string name);
    std::string task_name;
};

