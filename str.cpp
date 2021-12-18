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

String::String(int n): String() {
	assert(n > 0);

	data = new char[n];
	len = 0;
	cap = n;
}

String::String(const char* c_str): String(c_str, utils::c_str_len(c_str)) {
	// hmmm
}

String::String(char const* A, int n): String(n) {
	assert(A != NULL);

	utils::copy(A, data, n);
	len = n;
}

String::String(String const& other): String(other.cap) {
	len = other.len;

	if (other.len != 0) {
		assert(other.len > 0 && other.data != NULL);
		utils::copy(other.data, this->data, other.len);
	}
}

String::~String() {
	delete[] data;
}

String operator+ (String const& a, String const& b) {
	String str;
	str.len = str.cap = a.len + b.len;
	str.data = new char[str.len];

	utils::copy(a.data, str.data, a.len);
	utils::copy(b.data, str.data + a.len, b.len);

	return str;
}

String operator* (String const& src, int n) {
	assert(n > 0);

	String str;
	str.len = str.cap = src.len * n;
	str.data = new char[str.len];

	for(int i=0; i<n; i++) {
		utils::copy(
			src.data,
			str.data + (i*src.len),
			src.len
		);
	}

	return str;
}

std::ostream& operator<< (std::ostream& stream, const String& str) {
	for(int i=0; i < str.len; i++) {
		stream << str.data[i];
	}
	return stream;
}
