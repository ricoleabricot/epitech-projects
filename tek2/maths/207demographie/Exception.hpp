#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <iostream>

class Exception : public std::exception {
    std::string _message;

 public:
    Exception(std::string const &message) : _message(message) {}
    ~Exception() throw() {};

    const char *what() const throw() {
        return this->_message.c_str();
    }
};

#endif /* EXCEPTION_HPP_ */
