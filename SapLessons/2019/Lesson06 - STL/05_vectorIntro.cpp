#include <iostream>
#include <vector>
#include <iomanip> // std::setfill, std::setw
#include <algorithm>
#include <iterator>

void printVectorData(std::vector<int>& vec)
{
	std::cout << "Vector size: " << std::setfill(' ') << std::setw(2);
	std::cout << vec.size() << "; capacity: " << vec.capacity() << std::endl;

	std::cout << "Items: ";
	for (int value : vec)
	{
		std::cout << std::setfill(' ') << std::setw(4);
		std::cout << value << " ";
	}

	if (vec.empty())
	{
		std::cout << "-";
	}

	std::cout << std::endl;
}

int main()
{
	std::vector<int> userData;

	userData.reserve(10);
	for (int i = 0; i <= 10; ++i)
	{
		userData.push_back(i * i);
	}

	printVectorData(userData);

	std::cin.ignore();
	std::cin.get();

	return 0;
}

// Удаление с конца
//userData.pop_back();
//printVectorData(userData);

// Удаление произвольного элемента
//userData.erase(userData.begin() + 2);
//printVectorData(userData);

// Удаление произвольного элемента за константное врем¤
//std::swap(userData[2], userData[userData.size() - 1]);
//printVectorData(userData);
//userData.pop_back();
//printVectorData(userData);

// Удаление диапазона элементов
//userData.erase(userData.begin() + 2, userData.begin() + 5);
//printVectorData(userData);

// Удаление по значению
/*
auto foundIt = std::find(userData.begin(), userData.end(), 36);
if (foundIt != userData.end())
{
	userData.erase(foundIt);
}
printVectorData(userData);
*/

