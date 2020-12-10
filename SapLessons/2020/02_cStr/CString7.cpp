#include <cstring>
#include <iostream>

int main()
{
	char resultStr[255];
	char funcName[] = "strcat";

	strcpy(resultStr, funcName);
	strcat(resultStr, " function");
	strcat(resultStr, " concatenate strings");

	std::cout << "Result string size = " << strlen(resultStr) << "\n";
	std::cout << resultStr << "\n";
}