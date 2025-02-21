#include <iostream>
#include <cstring>
int main()
{
	char str[] = "My new string!";
	const int strLen = strlen(str);
	std::cout << str << "\n";

	char* currentSymb = &str[0];
	std::cout << "Inversion: ";
	for (char *i = currentSymb + strLen; currentSymb <= i; i--)
	{
		std::cout << *i;
	}

	return 0;
}