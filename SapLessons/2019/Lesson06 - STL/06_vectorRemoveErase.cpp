#include <iostream>
#include <vector>
#include <iomanip> // std::setfill, std::setw
#include <algorithm>
#include <iterator>
#include <cstdlib>

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
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL)); // initialize random seed

	std::vector<int> userData;
	userData.reserve(10);

	for (int i = 0; i <= 10; ++i)
	{
		int value = rand() % 5;
		userData.push_back(value);
	}
	printVectorData(userData);

	std::cin.ignore();
	std::cin.get();

	return 0;
}
/*
auto itEnd = std::remove(userData.begin(), userData.end(), 2);
printVectorData(userData);
*/

/*
userData.erase(itEnd, userData.end());
printVectorData(userData);
*/