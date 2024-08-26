#include "registers.h"

FlagRegister::FlagRegister(uint8_t initialData=0b0): reg_8bit(0b0) {
	setData(initialData);
}

uint8_t FlagRegister::getData(){
	 return DATA & 0b11010101;
}

void FlagRegister::setData(uint8_t newData){
	DATA = newData & 0b11010101;
}

void FlagRegister::resetFlags(){
	setData(0b0);
}

void FlagRegister::setCarry(bool set){
	if(set) DATA |= 0b00000001;
	else 	DATA &= 0b11111110;
}
void FlagRegister::setParity(bool set){
	if(set)	DATA |= 0b00000100;
	else	DATA &= 0b11111011;
}
void FlagRegister::setAuxCarry(bool set){
	if(set)	DATA |= 0b00010000;
	else	DATA &= 0b11101111;
}

void FlagRegister::setZero(bool set){
	if(set)	DATA |= 0b01000000;
	else	DATA &= 0b10111111;
}

void FlagRegister::setSign(bool set){
	if(set)	DATA |= 0b10000000;
	else	DATA &= 0b01111111;
}