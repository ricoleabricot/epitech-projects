/* 
* @Author: gicque_p
* @Date:   2015-04-14 11:13:39
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-23 20:35:12
*/

#include "Error.hpp"

Error::Error(std::string const &message, std::string const &type) : _message(message), _type(type) {}
const char *Error::what() const throw() {
	return this->_message.c_str();
}
const char *Error::where() const throw() {
	return this->_type.c_str();
}

ReceptionError::ReceptionError(std::string const &message) : Error(message, "ReceptionError") {}
PizzaError::PizzaError(std::string const &message) : Error(message, "PizzaError") {}
NamedPipeError::NamedPipeError(std::string const &message) : Error(message, "NamedPipeError") {}
ParsingError::ParsingError(std::string const &message) : Error(message, "ParsingError") {}
LogError::LogError(std::string const &message) : Error(message, "LogError") {}