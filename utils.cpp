#include <cstddef>
#include <iostream>
#include <cassert>

#include "utils.h"

void utils::copy(const char* src, char* dst, int len) {
	assert(src);
	assert(dst);
	assert(len > 0);

	for(int i=0; i<len; i++) {
		if(src[i] == '\0') {
			std::cerr << "WARNING: Copying null terminator character\n";
		}
		dst[i] = src[i];
	}
}

int utils::c_str_len(char const* c_str) {
	assert(c_str != NULL);

	char c;
	int i = 0;

	do {
		c = c_str[i];
		i++;
	} while (c != '\0');

	return i-1;
}
