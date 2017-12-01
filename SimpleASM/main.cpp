#include <iostream>
#include <fstream>

#include "SimpleASM.hpp"

int main(int argc, char* argv[])
{
	SimpleASM sasm;
	sasm.load("test.sasm");
	sasm.emit("test.c");
	return 0;
}