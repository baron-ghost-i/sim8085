#include "registers.h"

reg_8bit::reg_8bit(uint8_t data) {
	DATA = data;
}

uint8_t reg_8bit::getData() {
	return DATA;
}

void reg_8bit::setData(uint8_t newData) {
	DATA = newData;
}

GPR::GPR(uint8_t code, uint8_t data = 0b0): reg_8bit(data) {
	CODE = code;
}