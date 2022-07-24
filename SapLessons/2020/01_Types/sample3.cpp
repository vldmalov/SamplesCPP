#include<iostream>

int main()
{
	std::cout << "Different type sizes in bytes: \n";
	std::cout << "char      = " << sizeof(char)      << "\n";
	std::cout << "short     = " << sizeof(short)     << "\n";
	std::cout << "int       = " << sizeof(int)       << "\n";
	std::cout << "long      = " << sizeof(long)      << "\n";
	std::cout << "long long = " << sizeof(long long) << "\n";
}