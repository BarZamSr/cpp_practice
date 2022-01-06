#ifndef UTILS
#define UTILS


#include <cstddef>
#include <iostream>
#include <cassert>

#define ERR_VAL -1
#define FIB_LIM 100

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

	// singleton
	class Fibonacci {
	public:
		Fibonacci(Fibonacci & other) = delete;
		void operator= (const Fibonacci & other) = delete;

		static int bigger_than(int n) {
			int i = place_in_sequence(n);
			if(i == ERR_VAL) return ERR_VAL;

			return sequence[i];
		}
		static int smaller_than(int n) {
			int i = place_in_sequence(n);
			assert(i != ERR_VAL);
			if (i == 0) return sequence[0];
			return sequence[i - 1];
		}
	private:
		static Fibonacci * me;
		static int sequence[FIB_LIM];

		Fibonacci() {
			assert(sequence[0] == 0);

			sequence[0] = 8;
			sequence[1] = 13;
		}

		static int place_in_sequence(int n) {
			if(me == nullptr) {
				me = new Fibonacci();
			}
			for(int i=0; i<FIB_LIM; i++) {
				if(sequence[i] == 0) {
					sequence[i] = sequence[i-1] +
							sequence[i-2];
				}
				if(sequence[i] >= n) {
					return i;
				}
			}
			return ERR_VAL;
		}
	};

	Fibonacci * Fibonacci::me = nullptr;
	int Fibonacci::sequence[FIB_LIM] = {0};
}

#endif
