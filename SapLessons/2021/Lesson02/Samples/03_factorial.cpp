#include <iostream>

// 1. Точка старта приложения
// 2. Параметры командной строки (+ в общем случае на примере cd, ls, git)
// 3. Разбор параметров командной строки (вывод на экран, использование в коде)
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