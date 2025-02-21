#include <iostream>
#include <cstring>
#include  <string.h>

int main()
{
	char* strcpy(char* st1, const char* st2);
	char* strcat(char* st3, const char* funcName);
	char str[] = "My 012simple2 str3ing";
	char str_b[22];
	const int strLen = strlen(str);
	int i, j, n;
	n = strlen(str);
	int digiCount{0};

	char st1[25] = "Academy";
	char st2[25];

	char st3[255];
	char funcName[] = "bimacad ";

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

	//��������
	j = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		str_b[j] = str[i];
		j++;
	}

	//����������� ������
	strcpy(st2, st1);
	strcpy(st1, "Academy");

	//����������� �����
	strcpy(st3, funcName);
	strcat(st3, "is Bim Academy");

	std::cout << "\nDigi count = " << digiCount << "\n";
	std::cout << "\nLen = " << strLen << "\n"; //����� ������
	std::cout << str_b << "\n"; //��������

	std::cout << "st1=" << st1 << "\n"; //�����������
	std::cout << "st2=" << st2 << "\n";

	std::cout << "Result Union=" << strlen(st3) << "\n"; //�����������
	std::cout << "st3=" << st3 << "\n";

	return 0;
}