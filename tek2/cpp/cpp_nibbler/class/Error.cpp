/* 
* @Author: gicque_p
* @Date:   2015-03-10 12:30:15
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-11 21:14:53
*/

#include "Error.hpp"

Error::Error(std::string const &message, std::string const &type) : _message(message), _type(type) {}
const char *Error::what() const throw() {
	return this->_message.c_str();
}
const char *Error::where() const throw() {
	return this->_type.c_str();
}

CoreError::CoreError(std::string const &message) : Error(message, "CoreError") {}
PluginError::PluginError(std::string const &message) : Error(message, "PluginError") {}
DisplayError::DisplayError(std::string const &message, std::string const &type) : Error(message, type) {}
EarthWormError::EarthWormError(std::string const &message) : Error(message, "EarthWormError") {}
