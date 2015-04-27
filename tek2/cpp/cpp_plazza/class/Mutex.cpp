/* 
* @Author: gicque_p
* @Date:   2015-04-18 11:24:50
* @Last Modified by:   ribeir_b
* @Last Modified time: 2015-04-23 16:47:53
*/

#include "Mutex.hpp"

Mutex::Mutex(void) {
	pthread_mutex_init(&this->_id, NULL);
}

Mutex::~Mutex(void) {
	pthread_mutex_destroy(&this->_id);
}

int Mutex::lock(void) {
	return pthread_mutex_lock(&this->_id);
}

int Mutex::unlock(void) {
	return pthread_mutex_unlock(&this->_id);
}

int Mutex::trylock(void) {
	return pthread_mutex_trylock(&this->_id);	
}

pthread_mutex_t Mutex::getId(void) const {
	return this->_id;
}