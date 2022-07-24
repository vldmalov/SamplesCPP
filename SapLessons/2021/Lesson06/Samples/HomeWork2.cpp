#include <iostream>
#include <cstring>

char* revertStr(char* str)
{
	if(str == NULL) {
		return NULL;
	}

	const int strLen = strlen(str);
	for(int i = 0; i < strLen/2; ++i)
	{
		char temp = str[i];
		str[i] = str[strLen - 1 - i];
		str[strLen - 1 - i] = temp;
	}
	return str;
}

int main()
{
	char str1[] = "Simple string";
	char str2[] = "Another one simple string";

	char* res = revertStr(str1);
	std::cout << "res = " << res << std::endl;
	std::cout << "str1 = " << str1 << std::endl;
	
	return 0;
}