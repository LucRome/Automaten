#pragma once
#include "Statement.h"
#include <vector>
#include <memory>

class FSM
{
	std::vector<std::shared_ptr<Statement>> statement_list;
};

