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
				if (it + 1 == _prog.end())
				{
					buff += *it;
					if (is_opcode(buff))
						token_vector.push_back(Token(OPCODE, buff));
					else if (is_datatype(buff))
						token_vector.push_back(Token(DATATYPE, buff));
					else
						token_vector.push_back(Token(IDENTIFIER, buff));
					buff = "";
					return token_vector;
				}
				buff += *it++;
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
				else if (*it == '\"')
				{
					while (isalnum(*it) || ispunct(*it))
					{
						if (it + 1 == _prog.end() && *it == '"')
						{
							token_vector.push_back(Token(STRINGLITERAL, buff));
							buff = "";
							return token_vector;
						}
						buff += *it++;
					}
					if (isspace(*it) && *(it - 1) != '"')
					{
						token_vector.push_back(Token(ERRORTOKEN, buff));
					}
					else
					{
						// For some reason the " remains if we branch here, so remove it.
						buff.erase(buff.end()-1);
						token_vector.push_back(Token(STRINGLITERAL, buff));
						buff = "";
					}
				}
				else
					token_vector.push_back(Token(ERRORTOKEN, buff));
			}

		}
		if (isdigit(*it))
		{
			buff += *it;
			while (isdigit(*it++))
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
