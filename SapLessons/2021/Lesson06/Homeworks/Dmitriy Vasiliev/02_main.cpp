#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int char_length(char* s)
{
	int count = 0;
	while (*s != '\0') {
		count++;
		*s++;
	}

	return count;
}

char* char_inverse(char* s) 
{
	const int ch_l = char_length(s);
	char *p = new char[ch_l];

	for (int i = 0; i < ch_l; i++)
	{
		p[i] = s[ch_l - i - 1];
		cout << p[i] << " - [" << i << "]" << endl;
	}

	p[ch_l] = '\0';

	return p;
}

int main()
{
	char str[] = "My 012simple2 str3ing";
	char* str_ = str;
	char* one = str;
	cout << char_length(str_) << endl;

	char* res_inv = char_inverse(str_);
	cout << res_inv << endl;
	system("pause");

	return 0;
}
