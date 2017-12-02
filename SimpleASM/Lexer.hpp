#pragma once

#include <string>
#include <vector>

#include "Token.hpp"

class Lexer
{
	static std::vector<Token> token_vector;
public:
	Lexer();
	~Lexer();
	static std::vector<Token> lex_tokens(std::string _prog);
	static std::vector<Token> get_tokens();
};

