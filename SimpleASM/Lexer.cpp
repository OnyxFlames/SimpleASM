#include "Lexer.hpp"



Lexer::Lexer()
{
}


Lexer::~Lexer()
{
}

std::vector<Token> Lexer::lex_tokens(std::string _prog)
{
	std::string buff = "";
	for (
		auto it = _prog.begin();
		it != _prog.end(); it++)
	{
		if (isalpha(*it))
		{
			buff += *it++;
			while (isalnum(*it))
			{
				buff += *it++;
			}
			if (isspace(*it))
			{
				token_vector.push_back(Token(IDENTIFIER, buff));
				buff = "";
			}
		}
		if (isalnum(*it))
		{
			buff += *it;
			while (isalnum(*it++))
			{
				buff += *it;
			}
		}
	}
}
