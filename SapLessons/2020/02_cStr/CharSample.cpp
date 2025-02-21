#include <iostream>
#include <cstring>

int function()
{
	function();

	return 123;
}

int main()
{
	function();
	/*char str[] = "My simple string";
	const int strLen = strlen(str);

	char* currentSymb = &str[0];
	while(*currentSymb != '\0')
	{
		std::cout << *currentSymb << "\n";
		++currentSymb;
	}*/

	return 0;
}