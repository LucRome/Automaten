#pragma once
#include "Statement.h"
#include "Dec_Type.h"
#include "Event.h"
#include <vector>
#include <memory>

class Event_Declaration :
    public Statement
{
public:
	Event_Declaration();

    //delete/hide unused statement funcs/objects
	void push(State& s) = delete;

private:
	using Statement::state_list;
};

