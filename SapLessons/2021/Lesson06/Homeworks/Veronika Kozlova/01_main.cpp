#include <iostream>
#include <cstring>

int main()
{
	char str[] = "My 012simple2 str3ing";
	const int strLen = strlen(str);
	int Count=0;

	char* currentSymb = &str[strLen];
	while(Count!=strLen+1)
	{
		std::cout << *currentSymb;
		currentSymb = currentSymb - 1;

			++Count;
		
	}


	return 0;
}