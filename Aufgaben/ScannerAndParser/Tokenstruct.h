#pragma once
#include "TerminalsEnum.h"
#include <string>

struct Token {
	Terminals type;
	std::string name;	//for ID
};
