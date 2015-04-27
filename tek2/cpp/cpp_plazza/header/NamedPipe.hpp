//
// NamedPipe.hpp for Plazza in /home/boisso_c/rendu/cpp_plazza/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue Apr 21 14:38:38 2015 Christian Boisson
// Last update Thu Apr 23 15:42:31 2015 Christian Boisson
//

#ifndef		NAMEDPIPE_HPP_
# define	NAMEDPIPE_HPP_

# include	<string>
# include <stdio.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <fcntl.h>
#include  <sys/stat.h>

# include	"PipeData.hpp"
# include "Error.hpp"

enum		pipeMode
  {
    WRITE,
    READ
  };

class		NamedPipe
{
public:
  NamedPipe(const std::string &name, pipeMode mode);
  ~NamedPipe(void);
  int		getfd(void) const;
  void		writePipe(const PipeData &data);
  PipeData	*readPipe(void);
  static void	create(const std::string &name);
  void destroy(void);

  void		operator>>(const PipeData &data);
  PipeData	*operator<<(PipeData *data);
private:
  void		closePipe(void);
  int		openPipe(pipeMode mode);

  std::string	m_name;
  int		m_fd;
};

#endif		/* !NAMEDPIPE_HPP_ */
