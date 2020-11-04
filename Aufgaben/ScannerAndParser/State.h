#pragma once
#include "Dec_Type.h"
#include "Transition.h"
#include <string>
#include <vector>
#include <memory>

class State :
    public Dec_Type
{
public:
    State(std::string name, bool is_initial);

    bool initial;
    std::string state_name;
    
	//delete/hide unused Dec_Type elements
	void push(Event& e) = delete;
	void push(Task& t) = delete;
	void set_goto(State& s) = delete;

private:
	using Dec_Type::event_list;
	using Dec_Type::task_list;
	using Dec_Type::gotoState;
};

