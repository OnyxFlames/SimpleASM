#pragma once

#include <string>

/*

	Registers:
		Ri0 - Ri4	signed 32bit integers
		Ru0 - Ru4	unsigned 32bit integers
		Rd0 - Rd4	64bit floating point registers
		Rs0 - Rs4	string registers

	Opcodes:
		add RX RX RX	adds two register, stores result in 3rd register
		sub RX RX RX	subtracts two register, stores result in 3rd register
		mul RX RX RX	multiplies two registers, stores result in 3rd register
		div RX RX RX	divides two registers, stores result in 3rd register
		inc RX <value>	increments register by value
		dec RX <value>	decrements register by value
		ld	RX <value>	sets register to given value
*/


class SimpleASM
{
private:
	std::string emit_string = "";
public:
	SimpleASM();
	void load(const std::string& _file);
	void emit(const std::string& _file);
	~SimpleASM();
};
