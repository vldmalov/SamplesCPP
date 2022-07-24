#include <iostream>

unsigned int myStrlen(char* str)
{
	unsigned int len = 0;

	while (*str != '\0')
	{
		++len;
		++str;
	}
	return len;
}

void myInversion(char* str_orig, char* str_inver)
{
	unsigned int len = 0, size_str = 0;
	int i, j;
	len = myStrlen(str_orig);
	
	for (i = 0, j = len - 1; j >= 0; i++, j--)
	{
		str_inver[i] = str_orig[j];
	}
	str_inver[i] = '\0';
}

int main()
{
	char str_orig[50] = "My test string";
	char str_inver[30];

	myInversion(str_orig, str_inver);

	std::cout << "Original string: " << str_orig << std::endl;
	std::cout << "Copy string: " << str_inver << std::endl;

	getchar();
	return 0;
}