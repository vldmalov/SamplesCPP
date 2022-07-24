#include<iostream>

int main()
{
	unsigned char var1 = 39;  // 00100111
	unsigned char var2 = 246; // 10010010

	std::cout << "var size = " << sizeof(unsigned char) << " byte" << "\n";

	unsigned char sum = var1 + var2;
	std::cout << "Sum = " << (int)sum << "\n";
}