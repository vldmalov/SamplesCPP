#include <iostream>
#include <fstream>

// 1. Введение в файловые потоки
int factorial(int n)
{
	int result{ 1 };
	while(n > 1)
	{
		result *= n--;
	}

	return result;
}

int main()
{
	std::ifstream inFile("input.txt");
	std::ofstream outFile("output.txt");

	int arg;
	inFile >> arg;
	
	// std::cout << arg << "! = " << factorial(arg) << std::endl;
	outFile      << arg << "! = " << factorial(arg) << std::endl;
	return 0;
}