/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:38:43
*/

#ifndef CORE_HPP_
# define CORE_HPP_

# include <iostream>
# include <stack>

# include "Memory.hpp"
# include "IOperand.hpp"
# include "Error.hpp"

typedef void (Core::*operandFunction)(IOperand *);

class Core {
	Memory _memory;

 public:
	Core() {};
	~Core() {};

	void execute();

	Memory getMemory(void) const;
	void pushMemoryInstruction(operandFunction, IOperand *);

	void push(IOperand *);
	void pop(IOperand * = 0);
	void dump(IOperand * = 0);
	void assert(IOperand *);
	void add(IOperand * = 0);
	void sub(IOperand * = 0);
	void mul(IOperand * = 0);
	void div(IOperand * = 0);
	void mod(IOperand * = 0);
	void print(IOperand * = 0);
	void exit(IOperand * = 0);
};

#endif /* !CORE_HPP_ */
