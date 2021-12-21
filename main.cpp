#include <iostream>

#include "utils.h"
#include "str.h"

int main() {
	String str = "the quick brown fox jumps over the lazy dog";

	std::cout << String("Hello world").is_alpha();

	std::cout << '\n';
	return 0;
}
