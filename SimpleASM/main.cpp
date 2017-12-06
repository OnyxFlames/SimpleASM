#include <iostream>
#include <fstream>

#include "Lexer.hpp"
#include "Utils.hpp"
#include "SimpleASM.hpp"

int main(int argc, char* argv[])
{
	SimpleASM sasm;
	sasm.emit(
		Lexer::lex_tokens(
			filetostring(
				std::ifstream("../test.sasm"))));
	getchar();
	return 0;
}