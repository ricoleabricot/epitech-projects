#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <iostream>

class Error : public std::exception {
	std::string _message;

 public:
	Error(std::string const &message);
	~Error() throw() {};

	const char *what() const throw();

};

#endif /* !ERROR_HPP_ */
