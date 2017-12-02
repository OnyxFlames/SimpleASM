#include "Token.hpp"



Token::Token(Token_Type _type, std::string _value)
	:	type(_type), value(_value)
{
}


Token::~Token()
{
}

bool is_opcode(std::string _val)
{
	return false;
}

bool is_datatype(std::string _val)
{
	return false;
}
