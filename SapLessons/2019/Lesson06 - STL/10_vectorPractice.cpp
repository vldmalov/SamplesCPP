#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "Nothing to calculate" << std::endl;
		return 0;
	}

	std::cin.ignore();
	std::cin.get();

	return 0;
}

// 1. Сохранение данных в вектор
//std::vector<int> userData;
//for (int i = 1; i < argc; ++i)
//{
//	const int value = std::stoi(argv[i]);
//	userData.push_back(value);
//}

// 2. Не забыли про резервацию?

// std::accumulate

