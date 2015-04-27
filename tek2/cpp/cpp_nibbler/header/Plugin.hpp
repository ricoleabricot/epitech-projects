#ifndef PLUGIN_HPP_
# define PLUGIN_HPP_

# include <iostream>
# include <dlfcn.h>

# include "Error.hpp"

template <typename T>
class Plugin {
	void *_handle;

 public:
	Plugin() {};
	~Plugin() {};

	T *load(const std::string &lib) {

		T *(*instance)(void);
		if ((this->_handle = dlopen(lib.c_str(), RTLD_LAZY)) == NULL) {
			throw PluginError(dlerror());
		} else {
			if ((instance = reinterpret_cast<T *(*)()>(dlsym(this->_handle, "createModule"))) == NULL) {
				throw PluginError(dlerror());
			} else {
				T *module = instance();

				return module;
			}
		}
	}

	void unload(void) {
		if (this->_handle == NULL) {
			throw PluginError("Any dynamic library load");
		} else if (dlclose(this->_handle) != 0) {
			throw PluginError(dlerror());
		}
	}

};

#endif /* !PLUGIN_HPP_ */
