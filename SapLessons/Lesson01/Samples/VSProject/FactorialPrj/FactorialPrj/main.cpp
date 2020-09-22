#include <iostream>

// 1. Release/Debug
// 2. Отлака программы
// 3. Ожидание завершения выполнениия программы
// 4. Разбиваем на модули (раздельная компиляция, линковка)
// 4.1 Форвард декларейшен
// 4.2 Хидера

int factorial(int n)
{
	int result{ 1 };
	while (n > 1)
	{
		result *= n--;
	}

	return result;
}

int main()
{
	int arg{ 0 };
	std::cout << "Program enter factorial argument\n";
	std::cin >> arg;

	std::cout << arg << "! = " << factorial(arg) << std::endl;

	while (std::cin.get() != 'q') {};

	return 0;
}