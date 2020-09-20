#include <iostream>

int factorial(int n)
{
	int result{ 1 };
	while(n > 1)
	{
		result *= n--;
	}

	return result;
}

int main(int argc, const char* argv[])
{
	std::cout << "Program name is " << argv[0] << "\n";
	std::cout << "Input params count " << argc << std::endl;

	if(argc == 1) {
		std::cerr << "First programm param must be factorial arg" << std::endl;
		return 1;
	}

	int n = atoi(argv[1]);
	std::cout << n << "! = " << factorial(n) << std::endl;
	return 0;
}