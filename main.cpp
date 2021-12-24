#include <iostream>

#include "utils.h"
#include "list.h"
#include "list.cpp"

int main() {
	for(auto element: List<int>({1, 2, 3})) {
		std::cout << element << '\n';
	}
	return 0;
}
