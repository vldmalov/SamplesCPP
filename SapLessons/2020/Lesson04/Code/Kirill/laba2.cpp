#include <iostream>

void myStrcpy(char* str_copy, char* str_orig)
{
	unsigned int i = 0;
	while (*str_orig != '\0') 
	{
		str_copy[i] = str_orig[0];
		++str_orig;
		++i;
	}
	str_copy[i] = '\0';
}

int main()
{
	char str_orig[50] = "My test string";
	char str_copy[50];

	myStrcpy(str_copy, str_orig);

	std::cout << "Original string: " << str_orig << std::endl;
	std::cout << "Copy string: " << str_copy << std::endl;

	getchar();
	return 0;
}