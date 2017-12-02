#pragma once

#include <string>
#include <vector>

#include "Token.hpp"
/*

	Opcodes:
		hlt <code>		exit program returning
		add RX RX RX	adds two register, stores result in 1st register
		sub RX RX RX	subtracts two register, stores result in 1st register
		mul RX RX RX	multiplies two registers, stores result in 1st register
		div RX RX RX	divides two registers, stores result in 1st register
		inc RX <value>	increments register by value
		dec RX <value>	decrements register by value
		ld	<name> <datatype>	load variable referenced by name with datatypes
		lbl <name>		set label <name> that is referenced when using jump opcodes
		jmp <name>		jump to <label> and continue execution
		jlt	<name> <val> <comp>
						jump to label <name> if <val> is less than <comp>
		jgt <name> <val> <comp>
						jump to label <name> if <val> is greater than <comp>
		jlte	<name> <val> <comp>
						jump to label <name> if <val> is less than or equal to <comp>
		jgte <name> <val> <comp>
						jump to label <name> if <val> is greater than or equal to <comp>

		// Potentially implemented opcodes
		push <variable>	push variable for function call
		ccall <func> <name>
					call C function referenced by <func>, result is referenced by <name>
					//note: variables not pushed for ccall will be initialised to default value
	Keywords:
		using "<cfile>"	emits code to include c file by given name, quote or angled-brace sensitive

	Datatypes:
		[u8] and [i8],
		[u16] and [i16],
		[u32] and [i32],
		[u64] and [i64],
		[f32] and [f64],
			and	  [cstr]

*/


class SimpleASM
{
private:
	std::vector<Token> tokens;
public:
	SimpleASM();
	void emit(const std::string& _file);
	~SimpleASM();
};
