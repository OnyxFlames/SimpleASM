#pragma once

#include "Statement.hpp"
#include "Node.hpp"

class HaltStatement : public Statement
{
public:
	HaltStatement();
	~HaltStatement();
	virtual std::string emit() override;
	Ptr node;
};

