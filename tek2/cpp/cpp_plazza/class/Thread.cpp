/* 
* @Author: gicque_p
* @Date:   2015-04-18 15:06:43
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-18 15:11:20
*/

#include "Thread.hpp"

Thread::Thread(void *(routine)(void *), void *param) {
	pthread_create(&this->_id, NULL, routine, param);
}

Thread::~Thread(void) {}

void Thread::join(void) {
	pthread_join(this->_id, &this->_returnValue);
}

void *Thread::getReturnValue(void) const {
	return this->_returnValue;
}