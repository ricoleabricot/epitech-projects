#ifndef LOG_HPP_
# define LOG_HPP_

# include <iostream>
# include <fstream>
# include <sstream>

# include "Error.hpp"

class Log {
	std::string _filename;
	std::fstream _file;

	Log(const Log &);
	Log &operator=(const Log &);

 public:
	Log(const std::string &);
	~Log();

	void openIn(void);
	void openOut(void);
	void close(void);

	void changeLogFile(const std::string &);

	void write(const std::string &);
	void display(void);
	void flush(void);
};

#endif /* LOG_HPP_ */
