#include "Lexer.hpp"

#include "Utils.hpp"

std::vector<Token> Lexer::token_vector;

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
				if (it == _prog.end())
					return token_vector;
				buff += *it++;
				print_iterator(_prog, it);
			}
			if (isspace(*it))
			{
				if (is_opcode(buff))
					token_vector.push_back(Token(OPCODE, buff));
				else if (is_datatype(buff))
					token_vector.push_back(Token(DATATYPE, buff));
				else
					token_vector.push_back(Token(IDENTIFIER, buff));
				buff = "";
			}
			if (ispunct(*it))
			{
				if (*it == ':')
					token_vector.push_back(Token(LABELIDENTIFIER, buff));
				else
					token_vector.push_back(Token(ERRORTOKEN, buff));
			}

		}
		if (isalnum(*it))
		{
			buff += *it;
			while (isalnum(*it++))
			{
				buff += *it;
			}
			if (ispunct(*it))
			{
				if (*it == '.')
					token_vector.push_back(Token(FLOATLITERAL, buff));
				if (*it == ' ')
					token_vector.push_back(Token(INTLITERAL, buff));
			}
			// may be redundant
			if (isspace(*it))
			{
				token_vector.push_back(Token(INTLITERAL, buff));
			}
		}
	}
	return token_vector;
}

std::vector<Token> Lexer::get_tokens()
{
	std::vector<Token> ret = token_vector;
	token_vector.clear();
	return ret;
}
