#include "SimpleASM.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>

#include "Utils.hpp"


const std::string header_text =
{
"#include <stdio.h>\n"
"#include <stdint.h>\n\n"

"int32_t	Ri[8] = { 0 };\n"
"uint32_t	Ru[8] = { 0 };\n"
"double		Rd[8] = { 0 };\n"
"char*		Rs[8] = { 0 };\n"
};
const std::string footer_text =
{
	"return 0;\n"
	"}\n"
};


void to_lower(std::string& _val)
{
	for (auto& c : _val)
		c = tolower(c);
}

SimpleASM::SimpleASM()
{
}
// Very primitive way to emit code.
// This is more for proof-of-concept before a proper parse-tree is developed.
void SimpleASM::emit(std::vector<Token> _tokens)
{
	std::string emit_string = "";
	std::cout << "Token vector size: " << _tokens.size() << '\n';
	for (auto beg = _tokens.begin(); beg < _tokens.end(); beg++)
	{
		if (beg->type == OPCODE)
		{
			if ((beg)->value == "hlt")
			{
				beg++;
				emit_string += "exit(" + beg->value + ");\n";
			}
			else
			{
			}
		}
		else
		{
		}
	}
	std::cout << emit_string << "\n";
}


SimpleASM::~SimpleASM()
{
}
