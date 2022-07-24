#include <iostream>
#include <cstring>
#include <conio.h>
void fun(char*);
	char str[] = "My 012simple2 str3ing", str2[21];
	const int strLen = strlen(str);


int main()
{
char* currentSymb = &str[strLen];
	fun(currentSymb);
	std::cout << '\n';
	currentSymb = &str[strLen];
	fun(currentSymb);
	

	//std::cout << "\nDigi count = " << Count << "\n";
getch();
	return 0;
}
void fun(char* currentSymb)
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