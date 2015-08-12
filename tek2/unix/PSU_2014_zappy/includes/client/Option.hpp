//
// Option.hpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun 16 20:30:48 2015 rousse_3
// Last update Sat Jun 27 17:45:37 2015 rousse_3
//

#ifndef		OPTION_HPP_
# define	OPTION_HPP_

# include	<string>

class		Option
{
public:
  Option(int argc, const char **argv);
  Option(const Option &opt);
  ~Option(void) throw();

  void		getBName(std::string &bname) const;
  bool		isValid(void) const;
  void		getTeam(std::string &team) const;
  void		getIp(std::string &ip) const;
  int		getPort(void) const;
  const char	*getArg(void) const;

private:
  void		setTeam(int idx, int argc, const char **argv);
  void		setIp(int idx, int argc, const char **argv);
  void		setPort(int idx, int argc, const char **argv);

  std::string	_bname;
  bool		_isValid;
  std::string	_team;
  std::string	_ip;
  int		_port;
};

#endif
