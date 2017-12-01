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

void SimpleASM::load(const std::string&  _file)
{
	std::ifstream file(_file);

	if (!file.is_open())
	{
		std::cerr << "Failed to load source file.\n";
		std::exit(0);
	}
	std::string buffer = "";
	std::string resultbuff = "";
	while (file >> buffer)
	{
		resultbuff = "";
		if (buffer == "add")
		{
			file >> buffer;
			resultbuff += buffer + " + ";
			file >> buffer;
			resultbuff += buffer + ';';
			file >> buffer;
			emit_string += buffer + " = " + resultbuff + '\n';
			//std::cout << emit_string;
		}
		if (buffer == "sub")
		{
			file >> buffer;
			resultbuff += buffer + " - ";
			file >> buffer;
			resultbuff += buffer + ';';
			file >> buffer;
			emit_string += buffer + " = " + resultbuff + '\n';
			//std::cout << emit_string;
		}
		if (buffer == "mul")
		{
			file >> buffer;
			resultbuff += buffer + " * ";
			file >> buffer;
			resultbuff += buffer + ';';
			file >> buffer;
			emit_string += buffer + " = " + resultbuff + '\n';
			//std::cout << emit_string;
		}
		if (buffer == "div")
		{
			file >> buffer;
			resultbuff += buffer + " / ";
			file >> buffer;
			resultbuff += buffer + ';';
			file >> buffer;
			emit_string += buffer + " = " + resultbuff + '\n';
			//std::cout << emit_string;
		}
		if (buffer == "prt")
		{
			file >> buffer;
			//std::getline(file, resultbuff);
			if (buffer[1] == 's')
			{
				emit_string += "printf(\"%s\"," + resultbuff + ");\n";
			}
			if (buffer[1] == 'd')
			{
				emit_string += "printf(\"%f\"," + resultbuff + ");\n";
			}
			if (buffer[1] == 'i' || buffer[1] == 'u')
			{
				emit_string += "printf(\"%d\"," + resultbuff + ");\n";
			}
			std::cout << emit_string + '\n';
		}
		if (buffer == "ld")
		{

		}
	}
}

void SimpleASM::emit(const std::string & _file)
{
	std::ofstream file(_file);

	if (!file.is_open())
	{
		std::cerr << "Failed to load source file.\n";
		std::exit(0);
	}
	emit_string = header_text + emit_string;
	emit_string += footer_text;
	file << emit_string;
}


SimpleASM::~SimpleASM()
{
}
