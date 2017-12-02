#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "Token_Type.hpp"
#include "Token.hpp"


#define print_iterator(iter, curr) do { printf("it: %d end: %d\n", curr - iter.begin(), iter.end() - iter.begin()); } while(0);

std::string filetostring(std::ifstream& file);

std::vector<char> filetovector(std::ifstream& file);

std::string tokentypetostring(Token_Type tok);