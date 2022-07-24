#include <iostream>
#include <vector>
#include <iomanip> // std::setfill, std::setw
#include <algorithm>
#include <iterator>

void printVectorData(std::vector<int>& vec)
{
	std::cout << "Vector size: " << std::setfill(' ') << std::setw(2);
	//std::cout << vec.size() << "; capacity: " << vec.capacity() << std::endl;

	std::cout << "Items: ";
	for (int value : vec)
	{
		std::cout << std::setfill(' ') << std::setw(4);
		std::cout << value << " ";
	}

	//if (vec.empty())
	//{
	//	std::cout << "-";
	//}

	std::cout << std::endl;
}

int main()
{
	std::vector<int> userData = { 1, 2 };

	// Размер вектора и его вместимость (новая версия printVectorData)
	printVectorData(userData);


	std::cin.ignore();
	std::cin.get();

	return 0;
}

// Последовательное добавление элементов и проверка capacity
/*
for (int i = 3; i < 15; ++i)
{
	userData.push_back(i);
	printVectorData(userData);
}
*/

// Отчистка содержимого всего вектора (вместимость не изменилась)
/*
userData.clear();
printVectorData(userData);
*/

// Уменьшить вместимость вектора
/*
userData.shrink_to_fit();
printVectorData(userData);
*/

// Резервирование места под вектор
/*
userData.reserve(20);
for (int i = 1; i < 15; ++i)
{
	userData.push_back(i);
	printVectorData(userData);
}
*/
