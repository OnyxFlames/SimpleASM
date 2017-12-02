#include "Utils.hpp"

#include <map>
#include <streambuf>

// https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring

std::string filetostring(std::ifstream& file)
{
	std::string ret = "";

	file.seekg(std::ios::end);
	ret.reserve(file.tellg());
	file.seekg(std::ios::beg);
	ret.assign(
			std::istreambuf_iterator<char>(file),
			std::istreambuf_iterator<char>());
	return ret;
}

std::vector<char> filetovector(std::ifstream & file)
{
	return std::vector<char>();
}

std::string tokentypetostring(Token_Type tok)
{
	std::map<Token_Type, std::string> token_map = 
	{
		{UNKNOWN, "Unknown"},
		{OPCODE, "Opcode"},
		{IDENTIFIER, "Identifier"},
		{LABELIDENTIFIER, "LabelIdentifier"},
		{DATATYPE, "Datatype"},
		{INTLITERAL, "IntLiteral"},
		{FLOATLITERAL, "FloatLiteral"},
		{STRINGLITERAL, "StringLiteral"},
		{ERRORTOKEN, "ErrorToken"}
	};
	return token_map[tok];
}
