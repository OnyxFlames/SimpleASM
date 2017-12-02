#include "Utils.hpp"

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
