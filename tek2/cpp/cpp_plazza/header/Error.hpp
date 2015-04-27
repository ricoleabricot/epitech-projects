#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <iostream>

class Error : public std::exception {
 protected:
	std::string _message;
	std::string _type;

 public:
	Error(std::string const &message, std::string const &type);
	~Error() throw() {};

	const char *what() const throw();
	const char *where() const throw();
};

class ReceptionError : public Error {
 public:
	ReceptionError(std::string const &message);
	~ReceptionError() throw() {};
};

class PizzaError : public Error {
 public:
	PizzaError(std::string const &message);
	~PizzaError() throw() {};
};

class NamedPipeError : public Error {
 public:
	NamedPipeError(std::string const &message);
	~NamedPipeError() throw() {};
};

class ParsingError : public Error {
 public:
	ParsingError(std::string const &message);
	~ParsingError() throw() {};
};

class LogError : public Error {
 public:
	LogError(std::string const &message);
	~LogError() throw() {};
};

#endif /* ERROR_HPP_ */
