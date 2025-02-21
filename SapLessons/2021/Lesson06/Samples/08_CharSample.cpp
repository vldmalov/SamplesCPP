#include <iostream>
#include <cstring>
int main()
{
	char str[] = "My 012simple2 str3ing";
	const int strLen = strlen(str);
	int digiCount{0};

	char* currentSymb = &str[0];
	while(*currentSymb != '\0')
	{
		std::cout << *currentSymb;
		currentSymb = currentSymb + 1;

		if(isdigit(*currentSymb))
		{
			++digiCount;
		}
	}

	std::cout << "\nDigi count = " << digiCount << "\n";

	return 0;
}