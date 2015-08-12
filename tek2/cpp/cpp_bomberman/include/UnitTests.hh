/* 
* @Author: gicque_p
* @Date:   2015-02-11 19:11:17
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-11 20:11:17
*/

#ifndef UNITTESTS_HH_
# define UNITTESTS_HH_

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
        return !flag;
    }

    /**
        * Verify if given paremeters are equals (usable with numbers and strings only)
        *
        * @param T const &firstArg The first template value
        * @param U const &secondArg The second template value
    **/
    template <typename T, typename U>
    static bool isEqual(T const &firstArg, U const &secondArg) {
        return firstArg == secondArg;
    }

    /**
        * Verify if given parameters are not equals (usable with numbers and strings only)
        *
        * @param T const &firstArg The first template value
        * @param U const &secondArg The second template value
    **/
    template <typename T, typename U>
    static bool isNotEqual(T const &firstArg, U const &secondArg) {
        return firstArg != secondArg;
    }

    /**
        * Verify if first argument is greater than the second argument (usable with numbers)
        *
        * @param T const &greater The first template value supposed to be greater
        * @param U const &lower The second template value supposed to be lower
    **/
    template <typename T, typename U>
    static bool isGreaterThan(T const &greater, U const &lower) {
        return greater > lower;
    }

    /**
        * Verify if first argument is greater than or equal the second argument (usable with numbers)
        *
        * @param T const &greater The first template value supposed to be greater or equal
        * @param U const &lower The second template value supposed to be lower or equal
    **/
    template <typename T, typename U>
    static bool isGreaterThanOrEqual(T const &greater, U const &lower) {
        return greater >= lower;
    }

    /**
        * Verify if first argument is lower than the second argument (usable with numbers)
        *
        * @param T const &lower The first template value supposed to be lower
        * @param U const &greater The second template value supposed to be greater
    **/
    template <typename T, typename U>
    static bool isLowerThan(T const &lower, U const &greater) {
        return lower < greater;
    }

    /**
        * Verify if first argument is lower than or equal the second argument (usable with numbers)
        *
        * @param T const &lower The first template value supposed to be lower or equal
        * @param U const &greater The second template value supposed to be greater or equal
    **/
    template <typename T, typename U>
    static bool isLowerThanOrEqual(T const &lower, U const &greater) {
        return lower <= greater;
    }

    /**
        * Verify if given parameter is empty
        *
        * @param T const &empty The value of the content
    **/
    template <typename T>
    static bool isEmpty(T const &empty) {
        return empty == NULL or empty[0] == 0;
    }

    /**
        * Verify if given string is containing in given array of strings
        *
        * @param T const &search The constant reference of the searched value
        * @param U const &container The constant reference to the container
    **/
    template<template<class> class U, typename T>
    static bool isContainedIn(const T &search, const U<T> &container) {
        for (typename U<T>::iterator it = container.begin(); it != container.end(); it++) {
            if (*it == search) {
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

#endif /* !UNITTESTS_HH_ */
