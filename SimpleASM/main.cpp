#include <iostream>
#include <fstream>

#include "Lexer.hpp"
#include "Utils.hpp"

int main(int argc, char* argv[])
{
	for (const auto& t : Lexer::lex_tokens(
		filetostring(std::ifstream("../test.sasm"))))
	{
		std::cout << "[" << tokentypetostring(t.type) << "]\t\'" << t.value << "\'\n";
	}
	getchar();
	return 0;
}