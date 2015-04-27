/* 
* @Author: gicque_p
* @Date:   2015-02-18 16:07:36
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-21 20:07:23
*/

#include "Memory.hpp"

void Memory::pop(void) {
	this->_stack.pop();
}

void Memory::push(IOperand *operand) {
	this->_stack.push(operand);
}

void Memory::popInstruction(void) {
	this->_queue.pop();
}

void Memory::pushInstruction(operandFunction function, IOperand *operand) {
	this->_queue.push(std::make_pair(function, operand));
}

std::queue<std::pair<operandFunction, IOperand *> > Memory::getQueue(void) const {
	return this->_queue;
}

std::stack<IOperand *> Memory::getStack(void) const {
	return this->_stack;
}
