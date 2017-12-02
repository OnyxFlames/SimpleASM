#include <iostream>
#include <fstream>

#include "Lexer.hpp"
#include "Utils.hpp"

int main(int argc, char* argv[])
{
	Lexer::lex_tokens(
		filetostring(std::ifstream("../test.sasm")));
	getchar();
	return 0;
}