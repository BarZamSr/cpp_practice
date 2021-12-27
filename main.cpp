#include <iostream>

#include "list.cpp"

class Test {
public:
	Test() {
		std::cout << '+' << ++id << std::endl;
	}
	~Test() {
		std::cout << '-' << id << std::endl;
	}
private:
	static int id;
};

Test function() {
	Test * retval = new Test();
	return * retval;
}

int main() {
	// std::cout << List<int>({1, 2, 3}) * 2 << std::endl;
	
	return 0;
}
