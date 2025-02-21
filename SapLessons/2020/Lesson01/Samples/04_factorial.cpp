#include <iostream>
#include <fstream>

// 1. Введение в файловые потоки
// 2. Область видимости объектов inFile/outFile
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

	// file

	int arg;
	//std::cin >> arg;
	inFile >> arg;
	
	int result = factorial(arg);
	//std::cout << arg << "! = " << result << std::endl;
	outFile   << arg << "! = " << result << std::endl;
	return 0;

}