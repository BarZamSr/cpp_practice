#include <cstdlib>
#include <iostream>
#include <cassert>

#include "utils.h"
#include "str.h"


String::String() {
	data = NULL;
	len = 0;
	cap = 0;
}

String::String(int n) {
	assert(n>0);

	data = new char[n];
	len = 0;
	cap = n;
}

String::String(const char* A) {
	assert(A);

	char c;
	int i = 0;

	do {
		c = A[i];
		i++;
	} while (c != '\0');

	i--;

	data = new char[i];
	len = i;
	cap = i;

	utils::copy(A, data, i);
}

String::String(const char* A, int n): String(n) {
	assert(A);

	utils::copy(A, data, n);
	len = n;
}

String::String(String& other): String(other.cap) {
	len = other.len;

	if (other.len != 0) {
		assert(other.len > 0 && other.data != NULL);
		utils::copy(other.data, this->data, other.len);
	}
}

std::ostream& operator<< (std::ostream& stream, const String& str) {
	for(int i=0; i < str.len; i++) {
		stream << str.data[i];
	}

	return stream;
}
