/* 
* @Author: gicque_p
* @Date:   2015-04-18 12:15:24
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-18 12:19:04
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(const Mutex &mutex) : _mutex(mutex) {
	this->_mutex.lock();
}

ScopedLock::~ScopedLock(void) {
	this->_mutex.unlock();
}