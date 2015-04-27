/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:38:43
*/

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

# include <iostream>
# include <sstream>
# include <cstdlib>

enum eOperandType {
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

enum eOperandPrecision {
	LESS_ACCURATE = -2,
	MINUS_ACCURATE = -1,
	ACCURATE = 0,
	PLUS_ACCURATE = 1,
	MORE_ACCURATE = 2
};

class IOperand {
 public:
	virtual std::string const &toString(void) const = 0;

	virtual int getPrecision(void) const = 0;
	virtual eOperandType getType(void) const = 0;

	virtual IOperand *operator+(const IOperand &rhs) const = 0;
	virtual IOperand *operator-(const IOperand &rhs) const = 0;
	virtual IOperand *operator*(const IOperand &rhs) const = 0;
	virtual IOperand *operator/(const IOperand &rhs) const = 0;
	virtual IOperand *operator%(const IOperand &rhs) const = 0;

	virtual ~IOperand() {}
};

#endif /* !IOPERAND_HPP_ */
