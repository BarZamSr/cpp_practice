#ifndef UTILS
#define UTILS

#include <iostream>

#include <cstddef>
#include <cmath>
#include <cassert>

#define ERR_VAL -1
#define MIN_LIST_SIZE 8

#define LOG(x) std::cout << x << std::endl

namespace utils {
	template <class T>
	void copy(const T * source, T * destination, int length) {
		assert(source != nullptr);
		assert(destination != nullptr);
		assert(length > 0);

		const void * src = static_cast<const void *>(source);
		void * dest = static_cast<void *>(destination);
		std::size_t count = length * sizeof(T);
		std::memcpy(dest, src, count);
	}

	int c_str_len(char const* c_str) {
		assert(c_str != NULL);

		char c;
		int i = 0;

		do {
			c = c_str[i];
			i++;
		} while (c != '\0');

		return i-1;
	}

	bool is_num(char c) {
		return c >= '0' && c <= '9';
	}
	bool is_alpha(char c) {
		return  (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z');
	}
	bool is_whitespace(char c) {
		return c == ' ' || c == '\t' || c == '\n';
	}

	int nth_fib(int n) {
		assert(n >= 0);

		float Phi = (1 + sqrt(5)) / 2;
		float phi = (1 - sqrt(5)) / 2;

		return (pow(Phi, n) - pow(phi, n)) / sqrt(5);
	}
	int fib_before(int n) {
		assert(n > 0);

		int fib=0, last_fib;
		for(int i=0; fib < n; i++) {
			last_fib = fib;
			fib = nth_fib(i);
		}

		return last_fib;
	}
	int fib_after(int n) {
		assert(n >= 0);

		int fib=0;
		for(int i=0; fib <= n; i++) {
			fib = nth_fib(i);
		}

		return fib;
	}
}

#endif
