#ifndef SCOPEDLOCK_HPP_
# define SCOPEDLOCK_HPP_

# include "Mutex.hpp"

class ScopedLock {
	Mutex _mutex;

	ScopedLock(const ScopedLock &);
	ScopedLock &operator=(const ScopedLock &);

 public:
	ScopedLock(const Mutex &);
	~ScopedLock(void);
};

#endif /* SCOPEDLOCK_HPP_ */