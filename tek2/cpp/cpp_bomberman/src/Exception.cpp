/* 
* @Author: gicque_p
* @Date:   2015-05-20 09:31:38
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-12 15:51:15
*/

#include "Exception.hh"

Exception::Exception(const std::string &message, const std::string &type) : _message(message), _type(type) {}
Exception::~Exception() throw() {}

const char *Exception::what() const throw() {
	return this->_message.c_str();
}

const char *Exception::where() const throw() {
	return this->_type.c_str();
}

GameEngineException::GameEngineException(const std::string &message) : Exception(message, "GameEngine") {}
GameEngineException::~GameEngineException() throw() {}

DisplayException::DisplayException(const std::string &message) : Exception(message, "GDL") {}
DisplayException::~DisplayException() throw() {}

MapException::MapException(const std::string &message) : Exception(message, "Map") {}
MapException::~MapException() throw() {}

ItemException::ItemException(const std::string &message) : Exception(message, "Item") {}
ItemException::~ItemException() throw() {}

TextureLoaderException::TextureLoaderException(const std::string &message) : Exception(message, "TextureLoader") {}
TextureLoaderException::~TextureLoaderException() throw() {}
