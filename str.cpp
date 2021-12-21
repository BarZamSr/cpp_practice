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
	assert(n >= 0);

	if (n > 0) {
		data = new char[n];
		len = 0;
		cap = n;
	}
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

int String::find(char c) {
	return find(c, 0, len);
}
int String::find(char c, int start) {
	return find(c, start, len);
}
int String::find(char c, int start, int end) {
	assert(end <= len);
	for(int i = start; i < end; i++) {
		if (data[i] == c) return i;
	}
	return ERR_VAL;
}
int String::find(String const& substring) {
	return find(substring, 0, len);
}
int String::find(String const& substring, int start) {
	return find(substring, start, len);
}
int String::find(String const& substring, int start, int end) {
	for(int i=0; i<len; i++) {
		for(int j=0; i+j<len; j++) {
			if(j == substring.len) return i;
			if(data[i+j] != substring[j]) break;
		}
	}
	return ERR_VAL;
}

bool String::is_num() {
	for(char c: this) {
		if(!utils::is_alpha(c) && !utils::is_whitespace(c)) {
			return false;
		}
	}
	return true;
}
bool String::is_alpha() {
	for(char c: this) {
		if(!utils::is_alpha(c) && !utils::is_whitespace(c)) {
			return false;
		}
	}
	return true;
}

std::vector<String> String::split(char c) {
	std::vector<String> substrings;

	int curr=find(c), last=0;
	while(curr != ERR_VAL) {
		substrings.push_back(
			String(data+last, curr-last)
		);

		last = curr+1;
		curr = find(c, last);
	}
	substrings.push_back(
		String(data+last, len-last)
	);

	return substrings;
}

char & String::operator[] (int index) const {
	if(index < 0) {
		assert(0-index <= len);
		return data[len + index];
	}
	else {
		assert(index < len);
		return data[index];
	}
}

char* begin(String const& str) {
	return str.data;
}
char* begin(String const* str) {
	return str->data;
}
char* end(String const& str) {
	return str.data + str.len;
}
char* end(String const* str) {
	return str->data + str->len;
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
