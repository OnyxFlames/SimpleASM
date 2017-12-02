#pragma once

#include <string>
#include <vector>
#include <fstream>

#define print_iterator(iter, curr) do { printf("it: %d end: %d\n", curr - iter.begin(), iter.end() - iter.begin()); } while(0);

std::string filetostring(std::ifstream& file);

std::vector<char> filetovector(std::ifstream& file);