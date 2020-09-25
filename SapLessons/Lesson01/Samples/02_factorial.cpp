#include <iostream>

// 1. Включаемые файлы. Нейминг включаемых файлов стандартной библиотеки. Препроцессинг
// 2. Пространство имени std
// 3. Потоки ввода/вывода (коротко)
// Q1: Постфиксный/префиксные ++
// Q2: Переписать while на for
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
	int arg{ 0 };
	std::cout << "Program enter factorial argument\n";
	std::cin >> arg;

	std::cout << arg << "! = " << factorial(arg) << std::endl;
	return 0;
}