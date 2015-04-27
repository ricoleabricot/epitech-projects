/* 
* @Author: gicque_p
* @Date:   2015-03-02 14:59:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-02 14:59:46
*/

#include "Error.hpp"

Error::Error(std::string const &message) : _message(message) {}

const char *Error::what() const throw() {
	return this->_message.c_str();
}
