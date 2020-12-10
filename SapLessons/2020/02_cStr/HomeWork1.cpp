#include <iostream>


char* strcopy(char* dst, const char* src)
{
	if(dst == NULL)
	{
		return NULL;
	}

	char* res = dst;

	while(*src != '\0')
	{
		*dst++ = *src++;
	}

	*dst = '\0';

	return res;
}

int main()
{
	char str1[] = "Simple string";
	char str2[] = "Another one simple string";

	char* res = strcopy(str2, str1);
	strcopy(str1, "Copied string");
	std::cout << "res = " << res << std::endl;
	std::cout << "str1 = " << str1 << std::endl;
	std::cout << "str2 = " << str2 << std::endl;
	
	return 0;
}