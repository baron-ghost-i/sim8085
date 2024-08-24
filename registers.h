#include <stdio.h>
#include <iostream>
#include "types.h"

using namespace std;


class GPR{

	protected:
		uint8_t		DATA: 8;
		uint8_t		CODE: 3;
	
	public:

		uint8_t getCode() {return CODE;}

		uint8_t getData() {return DATA;}
		void setData(uint8_t newData) {DATA = newData;}

		//constructor
		GPR(uint8_t address, uint8_t data=0b0){
			CODE = address;
			DATA = data;
		}

};
typedef GPR Register;


class FlagRegister: public GPR{

	protected:
		uint8_t		CODE: 1;
	
	public:

		//constructor
		FlagRegister(uint8_t initialData = 0b0):GPR(0b0) {setData(initialData);}

		//applying bit mask to keep all non-flag values at zero
		uint8_t getData() {return DATA & 0b11010101;}
		void setData(uint8_t newData) {DATA = newData & 0b11010101;}
			
		void setCarry(bool set){
			if(set) DATA |= 0b00000001;
			else 	DATA &= 0b11111110;
		}

		void setParity(bool set) {
			if(set)	DATA |= 0b00000100;
			else	DATA &= 0b11111011;
		}

		void setAuxCarry(bool set) {
			if(set)	DATA |= 0b00010000;
			else	DATA &= 0b11101111;
		}

		void setZero(bool set) {
			if(set)	DATA |= 0b01000000;
			else	DATA &= 0b10111111;
		}

		void setSign(bool set) {
			if(set)	DATA |= 0b10000000;
			else	DATA &= 0b01111111;
		}

		void resetFlags() {setData(0b0);}
};


class RegisterPair: public GPR{

	private:
		uint16_t	DATA:	16;
		uint8_t		CODE:	2;

	public:

		//constructor
		RegisterPair(uint16_t initialData, uint8_t code):GPR(code) {DATA = initialData;}

		uint16_t getData() {return DATA;}
		void setData(uint16_t newData) {DATA = newData;}
};