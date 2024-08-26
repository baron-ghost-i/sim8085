#include <iostream>
#include "types.h"

using namespace std;

#ifndef REGISTERS_H
#define REGISTERS_H

class reg_8bit{
	/* General structure of 8-bit registers in 8085 */
	protected:
		uint8_t	DATA	: 8;
	public:
		//constructor
		reg_8bit(uint8_t data);

		uint8_t getData();
		void setData(uint8_t newData);
};

class GPR: public reg_8bit{
	/* General-purpose registers: B, C, D, E, H, L */
	protected:
		uint8_t CODE	: 3;
		uint8_t			: 0;
	public:
		GPR(uint8_t code, uint8_t data = 0b0);
};
typedef GPR Register;

class Accumulator: public GPR{
	/* Accumulator Register A */
	public:
		Accumulator(uint8_t data=0b0);
		//data transfer group functions
		void stax();
		void ldax();

		//arithmetic functions
		void add(Register R, FlagRegister* F, bool withCarry);
		void adi(uint8_t data, FlagRegister* F, bool withCarry);

		void sub(Register R, FlagRegister* F, bool withCarry);
		void sui(uint8_t data, FlagRegister* F, bool withCarry);

		void rlc();
		void rrc();
		void ral();
		void rar();

		void daa();
		void cma();

		//logical functions
		void ana(Register R, FlagRegister* F);
		void xra(Register R, FlagRegister* F);
		void ora(Register R, FlagRegister* F);
		void cmp(Register R, FlagRegister* F);
		void ani(uint8_t data, FlagRegister* F);
		void xri(uint8_t data, FlagRegister* F);
		void ori(uint8_t data, FlagRegister* F);
		void cpi(uint8_t data, FlagRegister* F);

		//io functions
		void out(uint8_t port);
		void in(uint8_t port);
};

class FlagRegister: public reg_8bit{
	/* Flag Register F */
	public:
		FlagRegister(uint8_t initialData = 0b0);

		uint8_t getData();
		void setData(uint8_t newData);
		
		void setCarry(bool set);
		void setParity(bool set);
		void setAuxCarry(bool set);
		void setZero(bool set);
		void setSign(bool set);
		void resetFlags() {setData(0);}
};

#endif