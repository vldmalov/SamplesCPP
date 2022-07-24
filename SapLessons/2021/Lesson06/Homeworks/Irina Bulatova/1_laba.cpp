#include <iostream>
#include <cstring>
int main()
{
	char str[] = "My new string!";
	const int strLen = strlen(str);
	int number{0};

	char* currentSymb = &str[0];
	while(*currentSymb != '\0')
	{
		std::cout << *currentSymb;
		currentSymb = currentSymb + 1;

			++number;
	}

	std::cout << "\nChar count = " << number << "\n";

	return 0;
}