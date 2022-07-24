#include<iostream>

int main()
{
	short var1 = 39;
	short var2 = 246;

	std::cout << "var size = " << sizeof(short) << " byte" << "\n";

	short sum = var1 + var2;
	std::cout << "Sum = " << sum << "\n";
}