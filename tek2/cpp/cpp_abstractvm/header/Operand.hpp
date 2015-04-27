/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:38:43
*/

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

# include "IOperand.hpp"
# include "Error.hpp"
# include "Hatchery.hpp"

template <typename T>
class Operand : public IOperand {
	T _value;
	eOperandType _type;
	eOperandPrecision _precision;

 public:
	Operand(const T value, eOperandType type, eOperandPrecision precision) : _value(value), _type(type), _precision(precision) {}
	~Operand() {}

	std::string const &toString(void) const {
		std::ostringstream buffer;

		buffer << this->_value;
		return (*new std::string(buffer.str()));
	}

	int getPrecision(void) const {
		return this->_precision;
	}

	eOperandType getType(void) const {
		return this->_type;
	}

	IOperand *operator+(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		std::istringstream firstBuffer(this->toString());
		std::istringstream secondBuffer(rhs.toString());
		std::ostringstream thirdBuffer;

		double firstValue;
		double secondValue;

		firstBuffer >> firstValue;
		secondBuffer >> secondValue;
		thirdBuffer << firstValue + secondValue;

		if (firstValue + secondValue < 2) {
			throw OperandError("Trying to push a result lower than 2");
		} else {
			if (this->getPrecision() <= rhs.getPrecision()) {
				operand = hatchery.createOperand(rhs.getType(), thirdBuffer.str());
			} else {
				operand = hatchery.createOperand(this->getType(), thirdBuffer.str());
			}
		}

		return operand;
	}

	IOperand *operator-(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		std::istringstream firstBuffer(this->toString());
		std::istringstream secondBuffer(rhs.toString());
		std::ostringstream thirdBuffer;

		double firstValue;
		double secondValue;

		firstBuffer >> firstValue;
		secondBuffer >> secondValue;
		thirdBuffer << firstValue - secondValue;

		if (firstValue - secondValue < 2) {
			throw OperandError("Trying to push a result lower than 2");
		} else {
			if (this->getPrecision() <= rhs.getPrecision()) {
				operand = hatchery.createOperand(rhs.getType(), thirdBuffer.str());
			} else {
				operand = hatchery.createOperand(this->getType(), thirdBuffer.str());
			}
		}

		return operand;
	}

	IOperand *operator*(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		std::istringstream firstBuffer(this->toString());
		std::istringstream secondBuffer(rhs.toString());
		std::ostringstream thirdBuffer;

		double firstValue;
		double secondValue;

		firstBuffer >> firstValue;
		secondBuffer >> secondValue;
		thirdBuffer << firstValue * secondValue;

		if (firstValue * secondValue < 2) {
			throw OperandError("Trying to push a result lower than 2");
		} else {
			if (this->getPrecision() <= rhs.getPrecision()) {
				operand = hatchery.createOperand(rhs.getType(), thirdBuffer.str());
			} else {
				operand = hatchery.createOperand(this->getType(), thirdBuffer.str());
			}
		}

		return operand;
	}

	IOperand *operator/(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		std::istringstream firstBuffer(this->toString());
		std::istringstream secondBuffer(rhs.toString());
		std::ostringstream thirdBuffer;

		double firstValue;
		double secondValue;

		firstBuffer >> firstValue;
		secondBuffer >> secondValue;
		thirdBuffer << firstValue / secondValue;

		if (firstValue / secondValue < 2) {
			throw OperandError("Trying to push a result lower than 2");
		} else {
			if (this->getPrecision() <= rhs.getPrecision()) {
				operand = hatchery.createOperand(rhs.getType(), thirdBuffer.str());
			} else {
				operand = hatchery.createOperand(this->getType(), thirdBuffer.str());
			}
		}

		return operand;
	}

	IOperand *operator%(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		std::istringstream firstBuffer(this->toString());
		std::istringstream secondBuffer(rhs.toString());
		std::ostringstream thirdBuffer;

		int firstValue;
		int secondValue;

		firstBuffer >> firstValue;
		secondBuffer >> secondValue;
		thirdBuffer << firstValue % secondValue;

		if (firstValue % secondValue < 2) {
			throw OperandError("Trying to push a result lower than 2");
		} else {
			if (this->getPrecision() <= rhs.getPrecision()) {
				operand = hatchery.createOperand(rhs.getType(), thirdBuffer.str());
			} else {
				operand = hatchery.createOperand(this->getType(), thirdBuffer.str());
			}
		}

		return operand;
	}
};

#endif /* OPERAND_HPP_ */
