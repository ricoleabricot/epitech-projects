/* 
* @Author: gicque_p
* @Date:   2015-04-14 11:08:51
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-22 14:45:59
*/

#include "Log.hpp"

Log::Log(const std::string &filename) : _filename(filename) {}
Log::~Log() {}

void Log::openIn(void) {

	this->_file.open(this->_filename.c_str(), std::fstream::in);

	if (!this->_file) {
		throw LogError("Can't open log file for input");
	}
}

void Log::openOut(void) {

	this->_file.open(this->_filename.c_str(), std::fstream::out | std::fstream::app);

	if (!this->_file) {
		throw LogError("Can't open log file for output");
	}
}

void Log::close(void) {
	this->_file.close();
}

void Log::changeLogFile(const std::string &filename) {
	this->_filename = filename;
}

void Log::write(const std::string &data) {
	this->openOut();
	this->_file << data << std::endl;
	this->close();
}

void Log::display(void) {
	char data[512];

	this->openIn();
	while (this->_file.getline(data, 512)) {
		std::cout << data << std::endl;
	}
	this->close();
}

void Log::flush(void) {
	this->_file.open(this->_filename.c_str(), std::fstream::out | std::fstream::trunc);
	this->_file.close();
}