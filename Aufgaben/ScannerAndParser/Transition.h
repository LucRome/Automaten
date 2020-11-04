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

	//delete/hide unused Dec_Type elements
	void push(Transition& t) = delete;

private:
	using Dec_Type::transition_list;
};

