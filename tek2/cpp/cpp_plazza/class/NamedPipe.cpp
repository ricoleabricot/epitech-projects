//
// NamedPipe.cpp for Plazza in /home/boisso_c/rendu/cpp_plazza/class
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue Apr 21 14:39:47 2015 Christian Boisson
// Last update Fri Apr 24 18:10:37 2015 Christian Boisson
//

#include	"NamedPipe.hpp"

NamedPipe::NamedPipe(const std::string &name, pipeMode mode) : m_name(name), m_fd(-1)
{
  openPipe(mode);
}

NamedPipe::~NamedPipe()
{
  if (m_fd)
	closePipe();
}

void NamedPipe::create(const std::string &name) {
	if (mkfifo(name.c_str(), S_IRUSR | S_IWUSR) != 0) {
		throw NamedPipeError("Cannot create named pipe");
	}
}

void NamedPipe::destroy(void) {
	remove(m_name.c_str());
}

int		NamedPipe::openPipe(pipeMode mode)
{
  if (m_fd == -1)
	{
	  if (mode == READ)
	m_fd = open(m_name.c_str(), O_RDONLY);
	  else if (mode == WRITE)
	m_fd = open(m_name.c_str(), O_WRONLY);
	}
  return (m_fd);
}

void		NamedPipe::closePipe(void)
{
  if (m_fd)
    {
      close(m_fd);
      m_fd = -1;
    }
}

int		NamedPipe::getfd(void) const
{
  return (m_fd);
}

void		NamedPipe::writePipe(const PipeData &data)
{
  if (m_fd != -1)
    write(m_fd, &data, sizeof(data));
}

PipeData	*NamedPipe::readPipe(void)
{
  PipeData	*tmp;

  tmp = new PipeData;
  read(m_fd, tmp, sizeof(PipeData));
  return (tmp);
}

void		NamedPipe::operator>>(const PipeData &data)
{
  writePipe(data);
}

PipeData	*NamedPipe::operator<<(PipeData *data)
{
  (void)data;
  return (readPipe());
}
