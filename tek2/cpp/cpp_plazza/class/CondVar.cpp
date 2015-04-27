/* 
* @Author: gicque_p
* @Date:   2015-04-18 11:57:02
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-20 16:01:19
*/

#include "CondVar.hpp"

CondVar::CondVar(void) {
	pthread_cond_init(&this->_id, NULL);
}

CondVar::~CondVar(void) {
	pthread_cond_destroy(&this->_id);
}

int CondVar::wait(pthread_mutex_t *mutex) {
	return pthread_cond_wait(&this->_id, mutex);
}

int CondVar::timedwait(pthread_mutex_t *mutex, const struct timespec *abstime) {
	return pthread_cond_timedwait(&this->_id, mutex, abstime);
}

int CondVar::signal(void) {
	return pthread_cond_signal(&this->_id);
}

int CondVar::broadcast(void) {
	return pthread_cond_broadcast(&this->_id);
}

pthread_cond_t CondVar::getId(void) const {
	return this->_id;
}