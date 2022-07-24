#include <iostream>
#include <cstring>

void fun(void);
	char str[] = "My 012simple2 str3ing", str2[21];
	const int strLen = strlen(str);
	char* currentSymb = &str[strLen];

int main()
{

	fun();
	std::cout << '\n';
	currentSymb = &str[strLen];
	fun();
	
	return 0;
}
void fun(void)
{
	int Count=0, i=0;
while(Count!=strLen+1)
	{
		std::cout << *currentSymb;
		str2[Count]=*currentSymb;
		currentSymb = currentSymb - 1;

			++Count;
	}
for(i=0;i<Count;i++)
str[i]=str2[i];
}