/* 
* @Author: gicque_p
* @Date:   2015-02-13 10:18:09
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-23 17:09:06
*/

#include "Hatchery.hpp"

Hatchery::Hatchery() {
	this->_arrayMethod[Int8] = &Hatchery::createInt8;
	this->_arrayMethod[Int16] = &Hatchery::createInt16;
	this->_arrayMethod[Int32] = &Hatchery::createInt32;
	this->_arrayMethod[Float] = &Hatchery::createFloat;
	this->_arrayMethod[Double] = &Hatchery::createDouble;
}

IOperand *Hatchery::createOperand(eOperandType type, const std::string &value) {
	if (this->_arrayMethod.find(type) != this->_arrayMethod.end()) {
		return (this->*_arrayMethod[type])(value);
	} else {
		throw HatcheryError("OperandType for array to member pointers undefined");
	}
}

IOperand *Hatchery::createInt8(const std::string &value) {
	short convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	if (convertedValue <= INT8_MIN) {
		throw HatcheryError("Underflow value for int8");
	} else if (convertedValue >= INT8_MAX) {
		throw HatcheryError("Overflow value for int8");
	} else {
		return new Operand<short>(convertedValue, Int8, LESS_ACCURATE);	
	}
}

IOperand *Hatchery::createInt16(const std::string &value) {
	int16_t convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	if (convertedValue <= INT16_MIN) {
		throw HatcheryError("Underflow value for int16");
	} else if (convertedValue >= INT16_MAX) {
		throw HatcheryError("Overflow value for int16");
	} else {
		return new Operand<int16_t>(convertedValue, Int16, MINUS_ACCURATE);	
	}
}

IOperand *Hatchery::createInt32(const std::string &value) {
	int32_t convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	if (convertedValue <= INT32_MIN) {
		throw HatcheryError("Underflow value for int32");
	} else if (convertedValue >= INT32_MAX) {
		throw HatcheryError("Overflow value for int32");
	} else {
		return new Operand<int32_t>(convertedValue, Int32, ACCURATE);	
	}
}

IOperand *Hatchery::createFloat(const std::string &value) {
	float convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	if (convertedValue <= -(std::numeric_limits<float>::max())) {
		throw HatcheryError("Underflow value for float");
	} else if (convertedValue >= std::numeric_limits<float>::max()) {
		throw HatcheryError("Overflow value for float");
	} else {
		return new Operand<float>(convertedValue, Float, PLUS_ACCURATE);	
	}
}

IOperand *Hatchery::createDouble(const std::string &value) {
	double convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	if (convertedValue <= -(std::numeric_limits<double>::max())) {
		throw HatcheryError("Underflow value for double");
	} else if (convertedValue >= std::numeric_limits<double>::max()) {
		throw HatcheryError("Overflow value for double");
	} else {
		return new Operand<double>(convertedValue, Double, MORE_ACCURATE);
	}
}
