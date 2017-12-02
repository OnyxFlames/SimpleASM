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
	if (
		_val == "hlt" ||
		_val == "add" ||
		_val == "sub" ||
		_val == "mul" ||
		_val == "div" ||
		_val == "inc" ||
		_val == "dec" ||
		_val == "ld" ||
		_val == "lbl" ||
		_val == "jmp" ||
		_val == "jlt" ||
		_val == "jgt" ||
		_val == "jlte" ||
		_val == "jgte" ||
		_val == "push" ||
		_val == "ccall")
		return true;
	return false;
}

bool is_datatype(std::string _val)
{
	if (
		_val == "u8" || _val == "i8" ||
		_val == "u16" || _val == "i16" ||
		_val == "u32" || _val == "i32" ||
		_val == "u64" || _val == "i64" ||
		_val == "f32" || _val == "f64" ||
		_val == "cstr")
		return true;
	return false;
}
