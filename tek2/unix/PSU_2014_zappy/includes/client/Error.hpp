//
// Error.hpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed Jun 17 19:39:32 2015 rousse_3
// Last update Wed Jun 17 20:14:27 2015 rousse_3
//

#ifndef				ERROR_HPP_
# define			ERROR_HPP_

# include			<string>
# include			<exception>
# include			<stdexcept>

class				ClientError : public std::exception
{
public:
  ClientError(void);
  ~ClientError(void) throw();
};

class				ConnectionError : public ClientError, public std::runtime_error
{
public:
  ConnectionError(const std::string &error);
  ~ConnectionError(void) throw();

  const char			*what(void) const throw();
private:
  const char			*_error;
};

#endif				/* !ERROR_HPP_ */
