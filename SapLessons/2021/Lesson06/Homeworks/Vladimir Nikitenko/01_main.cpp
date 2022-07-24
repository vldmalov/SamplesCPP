/// lab 1 -подсчёт символов строки
#include <iostream>
using namespace std;
int main()
{

	char Str[255] = "How many symbols in string?";	// строка

	int Symbol = 0;	// подсчёт символов
	while (Str[Symbol] != '\0')
	{
		Symbol++;
	}

	cout << Str << "\n" << "Symbols in string - " << Symbol;

	return 0;
}


/*lab2 - инверсия

#include <iostream>
using namespace std;

void main()
{
	char str[65] = "Reverse string";
	cout << str << endl; // вывод строки

	int len = strlen(str); //вычисление длины строки
	for (int j = 0; j < len / 2; j++) // изменение символов первой половины и второй половины
	{
		char temp = str[j];
		str[j] = str[len - j - 1];
		str[len - j - 1] = temp;
	}

	cout << str << endl; // вывод строки
}

*/

/*lab 3 - объединение строк


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	char str1[64] = "Если есть картошка";
	char str2[] = " Зачем есть капусту";

	cout << "Строка someText1 - \"" << str1 << "\" \n";
	cout << "Строка someText2 - \"" << str2 << "\" \n\n";
	strcat_s(str1, str2); // передаёт str2 в функцию

	cout << str1 << "\" \n\n";

	return 0;
}
*/