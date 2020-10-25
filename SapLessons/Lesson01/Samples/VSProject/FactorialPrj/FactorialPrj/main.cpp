#include <iostream>

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