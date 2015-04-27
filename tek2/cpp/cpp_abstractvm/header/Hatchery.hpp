/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:38:43
*/

#ifndef HATCHERY_HPP_
# define HATCHERY_HPP_

# include <map>
# include <limits>
# include <stdint.h>
# include <cfloat>

# include "Error.hpp"
# include "IOperand.hpp"

class Hatchery {

 private:
 	std::map<eOperandType, IOperand *(Hatchery::*)(const std::string &)> _arrayMethod;

	IOperand *createInt8(const std::string &);
	IOperand *createInt16(const std::string &);
	IOperand *createInt32(const std::string &);
	IOperand *createFloat(const std::string &);
	IOperand *createDouble(const std::string &);

 public:
	Hatchery();
	~Hatchery() {};

	IOperand *createOperand(eOperandType, const std::string &);
};

# include "Operand.hpp"

#endif /* !HATCHERY_HPP_ */
