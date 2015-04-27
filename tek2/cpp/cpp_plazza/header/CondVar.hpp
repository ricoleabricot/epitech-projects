#ifndef CONDVAR_HPP_
# define CONDVAR_HPP_

# include <pthread.h>

class CondVar {
	pthread_cond_t _id;

	CondVar(const CondVar &);
	CondVar &operator=(const CondVar &);

 public:
	CondVar(void);
	~CondVar(void);

	int wait(pthread_mutex_t *);
	int timedwait(pthread_mutex_t *, const struct timespec *);
	int signal(void);
	int broadcast(void);

	pthread_cond_t getId(void) const;
};

#endif /* CONDVAR_HPP_ */
