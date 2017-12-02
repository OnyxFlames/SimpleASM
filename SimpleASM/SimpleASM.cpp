#include "SimpleASM.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>



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


void SimpleASM::emit(const std::string & _file)
{
	std::ofstream file(_file);

	if (!file.is_open())
	{
		std::cerr << "Failed to load source file.\n";
		std::exit(0);
	}
}


SimpleASM::~SimpleASM()
{
}
