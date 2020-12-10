#include <iostream>
#include <vector>
#include <iomanip> // std::setfill, std::setw
//#include <algorithm> // find
//#include <iterator> // distance

void printVectorData(std::vector<int>& vec)
{
	std::cout << "Vector containes " << std::setfill(' ') << std::setw(2) << vec.size() << " items: ";
	for (int value : vec)
	{
		std::cout << std::setfill(' ') << std::setw(4);
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> userData = { 1, 2, 9, 16, 25, 36, 81, 100, 121 };

	printVectorData(userData);

	std::cin.ignore();
	std::cin.get();

	return 0;
}

// 1. Вставка в произвольное место вектора
/*
	userData.insert(userData.begin() + 2, 4);
	userData.insert(userData.begin() + 7, 49);
	userData.insert(userData.end() - 3, 64);
	printVectorData(userData);
*/

// 2. Итераторы. Введение. Итератор begin и end

// 3. Введение в алгоритмы. Поиск нужного элемента
// 3.1 Проверка, что он найден
/*
std::vector<int>::iterator it = std::find(userData.begin(), userData.end(), 36);
if (it == userData.end())
{
	std::cout << "Item " << 36 << " didn't find in vector\n";
}
else
{
	std::cout << "Item " << 36 << " has been found!\n";
	std::cout << "The distance from vector begin is: " << std::distance(userData.begin(), it) << '\n';

	*it = 10;
}
printVectorData(userData);
*/