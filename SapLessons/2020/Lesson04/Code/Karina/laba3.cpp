#include <iostream>

void myStrcat(char* str_start, char* str_end, char* str_result)
{
	unsigned int i = 0;
	while (*str_start != '\0')
	{
		str_result[i] = str_start[0];
		++str_start;
		++i;
	}
	while (*str_end != '\0')
	{
		str_result[i] = str_end[0];
		++str_end;
		++i;
	}
	str_result[i] = '\0';
}

int main()
{
	char str_start[50] = "Start ";
	char str_end[50] = "End";
	char str_result[100];
	
	myStrcat(str_start, str_end, str_result);

	std::cout << "String start: " << str_start << std::endl;
	std::cout << "String end: " << str_end << std::endl;
	std::cout << "String result: " << str_result << std::endl;

	getchar();
	return 0;
}