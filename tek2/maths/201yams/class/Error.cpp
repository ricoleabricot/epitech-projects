/* 
* @Author: gicque_p
* @Date:   2015-02-22 17:18:47
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-22 17:18:57
*/

#include "Error.hpp"

Error::Error(std::string const &message) : _message(message) {}

const char *Error::what() const throw() {
	return this->_message.c_str();
}
