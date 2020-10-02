#include <iostream>
#include <iomanip>

// 1. Release/Debug (показать результирующие файлы)
// 2. Переполнение типа (про размеры типов и что это значит)
// 3. Форматирование вывода
// 3. Отлака программы
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

	//std::cout << std::setw(22) << std::left << "Sizeof short is " << sizeof(short) << std::endl;
	//std::cout << std::setw(22) << std::left << "Sizeof int is " << sizeof(int) << std::endl;
	//std::cout << std::setw(22) << std::left << "Sizeof long is " << sizeof(long) << std::endl;
	//std::cout << std::setw(22) << std::left << "Sizeof long long is " << sizeof(long long) << std::endl;
	while (!std::cin.fail())
	{
		std::cout << "Enter factorial argument (int) or any other key to exit: ";
		if(std::cin >> arg)
		{
			std::cout << arg << "! = " << factorial(arg) << std::endl;
		}
	};

	return 0;
}