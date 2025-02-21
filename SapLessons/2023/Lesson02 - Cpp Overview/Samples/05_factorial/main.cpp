#include "factorial.h"
#include <iostream>

// 1. Раздельная компиляция
// 2. Объявление/определение функции
// 3. Пример объявления без хидера (проблемы)
// 4. Что можно писать в хидерах
// 5. include guards
// 6. Ошибки компиляции и линковки
int main()
{
	int arg{ 0 };
	std::cout << "Program enter factorial argument\n";
	std::cin >> arg;

	std::cout << arg << "! = " << factorial(arg) << std::endl;
	return 0;
}