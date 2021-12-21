#include <cstddef>
#include <iostream>
#include <cassert>

#include "utils.h"

namespace utils {
	void copy(const char* src, char* dst, int len) {
		assert(src != NULL);
		assert(len >= 0);
		assert(len == 0 || dst != NULL);

		for(int i=0; i<len; i++) {
			if(src[i] == '\0') {
				std::cerr << "WARNING: Copying null terminator character\n";
			}
			dst[i] = src[i];
		}
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
}
