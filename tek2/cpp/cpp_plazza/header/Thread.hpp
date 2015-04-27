#ifndef THREAD_HPP_
# define THREAD_HPP_

# include <pthread.h>

class Thread {
	pthread_t _id;
	void *_returnValue;

	Thread(const Thread &);
	Thread &operator=(const Thread &);

 public:
	Thread(void *(routine)(void *), void * = NULL);
	~Thread(void);

	void join(void);

	void *getReturnValue(void) const;
};

#endif /* THREAD_HPP_ */
