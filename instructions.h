#include <iostream>
using namespace std;

class Instruction{
	protected:
		uint8_t Opcode;
};

class Instruction_2Bytes: public Instruction{
	protected:
		uint8_t Data;
};

class Instruction_3Bytes: public Instruction{
	protected:
		uint8_t AddressByte1;
		uint8_t AddressByte2;
};