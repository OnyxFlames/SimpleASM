#pragma once

#include <string>

#include "Node.hpp"

class Statement : public Node
{
public:
	Statement();
	~Statement();
	virtual std::string emit() = 0;
};

