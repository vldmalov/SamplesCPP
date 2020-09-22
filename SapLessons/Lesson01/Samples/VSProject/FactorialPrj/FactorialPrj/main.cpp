#include <iostream>

// 1. Release/Debug
// 2. ������ ���������
// 3. �������� ���������� ����������� ���������
// 4. ��������� �� ������ (���������� ����������, ��������)
// 4.1 ������� �����������
// 4.2 ������

int factorial(int n)
{
	int result{ 1 };
	while (n > 1)
	{
		result *= n--;
	}

	return result;
}

int main()
{
	int arg{ 0 };
	std::cout << "Program enter factorial argument\n";
	std::cin >> arg;

	std::cout << arg << "! = " << factorial(arg) << std::endl;

	while (std::cin.get() != 'q') {};

	return 0;
}