#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <iostream>

class Exception : public std::exception {
    std::string _message;
    std::string _type;

 public:
    Exception(const std::string &, const std::string &);
    ~Exception() throw();

    const char *what() const throw();
    const char *where() const throw();
};

class GameEngineException : public Exception {
 public:
    GameEngineException(const std::string &);
    ~GameEngineException() throw();
};

class DisplayException : public Exception {
 public:
    DisplayException(const std::string &);
    ~DisplayException() throw();
};

class MapException : public Exception {
 public:
    MapException(const std::string &);
    ~MapException() throw();
};

class ItemException : public Exception {
 public:
    ItemException(const std::string &);
    ~ItemException() throw();
};

class TextureLoaderException : public Exception {
 public:
    TextureLoaderException(const std::string &);
    ~TextureLoaderException() throw();
};

#endif /* EXCEPTION_HPP_ */
