#include <iostream>

#include "utils.h"
#include "list.h"
#include "str.h"

int main() {
	int array[3] = {1, 2, 3};

	std::cout << List<int>(array, 3);

	std::cout << '\n';
	return 0;
}
