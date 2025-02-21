#include <iostream>
#include <vector>
// #include <iomanip> // std::setfill, std::setw

int main()
{
	std::vector<int> userData = { 1, 2, 4, 9, 16, 25, 36 };

	std::cout << "User data containes " << userData.size() << " items: ";
	for (int itemVal : userData)
	{
		std::cout << itemVal << " ";
	}
	std::cout << std::endl;

	userData[2] = 500;
	userData[6] = 1;

	userData.push_back(49);
	userData.push_back(64);
	userData.push_back(81);
	userData.push_back(100);
	userData.push_back(121);

	for (int itemVal : userData)
	{
		std::cout << itemVal << " ";
	}
	std::cout << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}

// 1. Показать выход за границы
//userData[7] = 1;

// 2. Копипаст вывода вектора

// 3. Манипуляторы вывода
//#include <iomanip>
//std::cout << std::setfill(' ') << std::setw(4);

// 4. Переносим печать в функцию (показать на примере правки манипуляторов в условиях копипаста)
// Принцип DRY

// 5. Операция удаления с конца вектора
// userData.pop_back();

// 6. Сортировка по критерию
/*std::sort(userData.begin(), userData.end(),
	[](const std::string& lhs, const std::string& rhs)
{
	return lhs.size() < rhs.size();
});*/