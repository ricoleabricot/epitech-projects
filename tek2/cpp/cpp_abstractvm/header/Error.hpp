/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:38:43
*/

#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <iostream>

class HatcheryError : public std::exception {
	std::string _message;

 public:
	HatcheryError(std::string const &message);
	~HatcheryError() throw() {};

	const char *what() const throw();

};

class CoreError : public std::exception {
	std::string _message;

 public:
	CoreError(std::string const &message);
	~CoreError() throw() {};

	const char *what() const throw();

};

class OperandError : public std::exception {
	std::string _message;

 public:
	OperandError(std::string const &message);
	~OperandError() throw() {};

	const char *what() const throw();

};

class ParsingError : public std::exception {
	std::string _message;

 public:
	ParsingError(std::string const &message);
	~ParsingError() throw() {};

	const char *what() const throw();

};

#endif /* !ERROR_HPP_ */
