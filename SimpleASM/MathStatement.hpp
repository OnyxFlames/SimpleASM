#pragma once

#include "Statement.hpp"

class MathStatement : public Statement
{
public:
	MathStatement();
	~MathStatement();

	// Inherited via Statement
	virtual std::string emit() override;
	std::vector<Ptr> children;
};

