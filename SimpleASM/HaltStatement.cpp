#include "HaltStatement.hpp"



HaltStatement::HaltStatement()
{
}


HaltStatement::~HaltStatement()
{
}

std::string HaltStatement::emit()
{
	//return "std::exit(" + node->value + ");\n";
	return "";
}
