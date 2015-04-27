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

class CoreError : public Error {
 public:
	CoreError(std::string const &message);
	~CoreError() throw() {};
};

class PluginError : public Error {
 public:
	PluginError(std::string const &message);
	~PluginError() throw() {};
};

class DisplayError : public Error {
 public:
	DisplayError(std::string const &message, std::string const &type);
	~DisplayError() throw() {};
};

class EarthWormError : public Error {
 public:
	EarthWormError(std::string const &message);
	~EarthWormError() throw() {};
};

#endif /* !ERROR_HPP_ */
