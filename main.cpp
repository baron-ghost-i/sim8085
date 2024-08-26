#include <iostream>
#include "types.h"
#include "registers.h"

int main(){
	Accumulator	A(Reg::A);
	Register	B(Reg::B, 0x00);
	Register	C(Reg::C, 0x00);
	Register	D(Reg::D, 0x00);
	Register	E(Reg::E, 0x00);
	Register	H(Reg::H, 0x00);
	Register	L(Reg::L, 0x00);

	int8_t  	Memory[0xFFFF];
}