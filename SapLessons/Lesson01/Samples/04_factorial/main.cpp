#include "factorial.h"
#include <iostream>

int main()
{
	int arg{ 0 };
	std::cout << "Program enter factorial argument\n";
	std::cin >> arg;

	std::cout << arg << "! = " << factorial(arg) << std::endl;
	return 0;
}