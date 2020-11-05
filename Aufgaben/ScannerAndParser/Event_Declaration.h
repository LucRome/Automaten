#pragma once
#include "Statement.h"
#include <vector>

class Event_Declaration
	: public Statement
{
public:
	void push(std::shared_ptr<Event> ev) override;
private:
	std::vector<std::shared_ptr<Event>> event_list;
};

