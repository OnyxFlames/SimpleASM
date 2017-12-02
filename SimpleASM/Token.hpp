#pragma once

#include <string>
#include "Token_Type.hpp"

struct Token
{
	Token_Type type = UNKNOWN;
	std::string value = "";

	Token(Token_Type _type, std::string _value);
	~Token();
};

bool is_opcode(std::string _val);
bool is_datatype(std::string _val);