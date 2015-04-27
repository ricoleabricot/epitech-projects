/* 
* @Author: gicque_p
* @Date:   2015-02-11 19:11:17
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-11 20:11:17
*/

#ifndef UNITTESTS_HPP_
# define UNITTESTS_HPP_

# include <iostream>
# include <cstdlib>

class UnitTests {
 public:

	/**
		* Verify if given bool is true
		*
		* @param bool flag The Boolean value
	**/
	static bool isTrue(bool flag) {
		return flag;
	}

	/**
		* Verify if given bool is false
		*
		* @param bool flag The Boolean value
	**/
	static bool isFalse(bool flag) {
		if (flag == false) {
			return true;
		} else {
			return false;
		}
	}

	/**
		* Verify if given paremeters are equals (usable with numbers and strings only)
		*
		* @param T const &firstArg The first template value
		* @param U const &secondArg The second template value
	**/
	template <typename T, typename U>
	static bool isEqual(T const &firstArg, U const &secondArg) {
		if (firstArg == secondArg) {
			return true;
		} else {
			return false;
		}
	}

	/**
		* Verify if given parameters are not equals (usable with numbers and strings only)
		*
		* @param T const &firstArg The first template value
		* @param U const &secondArg The second template value
	**/
	template <typename T, typename U>
	static bool isNotEqual(T const &firstArg, U const &secondArg) {
		if (firstArg != secondArg) {
			return true;
		} else {
			return false;
		}
	}

	/**
		* Verify if first argument is greater than the second argument (usable with numbers)
		*
		* @param T const &greater The first template value supposed to be greater
		* @param U const &lower The second template value supposed to be lower
	**/
	template <typename T, typename U>
	static bool isGreaterThan(T const &greater, U const &lower) {
		if (greater > lower) {
			return true;
		} else {
			return false;
		}
	}

	/**
		* Verify if first argument is greater than or equal the second argument (usable with numbers)
		*
		* @param T const &greater The first template value supposed to be greater or equal
		* @param U const &lower The second template value supposed to be lower or equal
	**/
	template <typename T, typename U>
	static bool isGreaterThanOrEqual(T const &greater, U const &lower) {
		if (greater >= lower) {
			return true;
		} else {
			return false;
		}
	}

	/**
		* Verify if first argument is lower than the second argument (usable with numbers)
		*
		* @param T const &lower The first template value supposed to be lower
		* @param U const &greater The second template value supposed to be greater
	**/
	template <typename T, typename U>
	static bool isLowerThan(T const &lower, U const &greater) {
		if (lower < greater) {
			return true;
		} else {
			return false;
		}
	}

	/**
		* Verify if first argument is lower than or equal the second argument (usable with numbers)
		*
		* @param T const &lower The first template value supposed to be lower or equal
		* @param U const &greater The second template value supposed to be greater or equal
	**/
	template <typename T, typename U>
	static bool isLowerThanOrEqual(T const &lower, U const &greater) {
		if (lower <= greater) {
			return true;
		} else {
			return false;
		}
	}

	/**
		* Verify if given parameter is empty
		*
		* @param T const &empty The value of the content
	**/
	template <typename T>
	static bool isEmpty(T const &empty) {
		if (empty == NULL or empty[0] == 0) {
			return true;
		} else {
			return false;
		}
	}

	/**
		* Verify if given string is containing in given array of strings
		*
		* @param std::string const &string The constant reference string value
		* @param std::string const *arrayString The array of constant referance string to look for
	**/
	static bool isContaining(std::string const &searchString, std::string const *arrayString) {
		for (size_t i = 0; i < arrayString->size(); i++) {
			if (searchString == arrayString[i]) {
				return true;
			}
		}

		return false;
	}

	/**
		* Verify if given file exists (overloaded with std::ofstream)
		*
		* @param T const &file The filename to test if exists
	**/
	template <typename T>
	static bool fileExists(T const &file) {
		if (file) {
			return true;
		} else {
			return false;
		}
	}
};

# define printError(error) \
	std::cerr << "\033[01;31mUnitTest error: \"" << error; \
	std::cerr << "\" catch in file: " << __FILE__; \
	std::cerr << ", in function: " << __FUNCTION__; \
	std::cerr << ", at line: " << __LINE__; \
	std::cerr << "\033[0m" << std::endl;

#endif /* !UNITTESTS_HPP_ */
