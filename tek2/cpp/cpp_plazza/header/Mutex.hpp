#ifndef MUTEX_HPP_
# define MUTEX_HPP_

# include <pthread.h>

class Mutex {
	pthread_mutex_t _id;

 public:
	Mutex(void);
	~Mutex(void);

	int lock(void);
	int unlock(void);
	int trylock(void);

	pthread_mutex_t getId(void) const;
};

#endif /* MUTEX_HPP_ */
