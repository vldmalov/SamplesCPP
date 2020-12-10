#include <iostream>
//#include <string>
//#include <cstring>

template<typename T>
T GetMin(T a, T b)
{
	return a < b ? a : b;
}

int main()
{
	std::cout << "Min value is " << GetMin(300, 12) << std::endl;
	std::cout << "Min value is " << GetMin(3.1415, 2.71) << std::endl;
	std::cout << "Min value is " << (char)GetMin('a', 'z') << std::endl;
	//std::cout << "Min value is " << GetMin(std::string("Intel"), std::string("AMD")) << std::endl;

	std::cin.ignore();
	std::cin.get();
}

// 1. Специализация шаблона const char*

//const char* GetMin(const char* lhs, const char* rhs)
//{
//	return lhs < rhs ? lhs : rhs;
//}

// 2.
// const char* GetMin(const char* a, const char* b)
// {
// 	if (std::strcmp(a, b) < 0)
// 	{
// 		return a;
// 	}
// 	return b;
// }

// 3. std::string

// std::cout << "Min value is " << GetMin(std::string("Alex"), std::string("Jack")) << std::endl;