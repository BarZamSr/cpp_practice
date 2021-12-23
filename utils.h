#ifndef UTILS
#define UTILS

#define ERR_VAL -1
#define ACII_LEN 128

namespace utils {
	template <class T>
	void copy(T const*, T*, int);

	int c_str_len(char const*);
	bool is_alpha(char);
	bool is_num(char);
	bool is_whitespace(char);
}

#include "utils.cpp"

#endif
