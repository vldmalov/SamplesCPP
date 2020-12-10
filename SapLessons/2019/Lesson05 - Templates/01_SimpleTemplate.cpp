#include<iostream>

int GetMin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	std::cout << GetMin(123, -45) << '\n';

	std::cin.ignore();
	std::cin.get();
}

// 1. Пример для типов float, char
// 2. Для char код символа. Приведение