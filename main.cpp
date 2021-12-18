#include <iostream>

#include "utils.h"
#include "str.h"

int main() {
	String** strings = new String*[4];
	strings[0] = new String();
	strings[1] = new String(5);
	strings[2] = new String("hello");
	strings[3] = new String("hello", 4);

	for (int i=0; i<4; i++) {
		std::cout << *strings[i] << '\n';
		delete strings[i];
	}

	delete[] strings;

	return 0;
}
