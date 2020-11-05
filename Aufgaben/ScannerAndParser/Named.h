#pragma once
#include "Node.h"
#include <string>

class Named : public Node
{
public:
	std::string getName();
	void setName(std::string name);

private:
	std::string m_name = "";
};

