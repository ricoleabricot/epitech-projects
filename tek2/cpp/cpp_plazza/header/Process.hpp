#ifndef PROCESS_HPP_
# define PROCESS_HPP_

# include	<unistd.h>

class Process {
	Process(const Process &);
	Process &operator=(const Process &);

 public:
	Process(void);
	~Process(void);
  static int createProcess(void);
};

#endif /* PROCESS_HPP_ */
