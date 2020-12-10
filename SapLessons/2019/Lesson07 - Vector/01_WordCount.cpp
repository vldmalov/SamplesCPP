#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string inputString{ "Dreiser was the ninth of 10 surviving children in a family whose perennial poverty forced frequent moves between small Indiana towns and Chicago in search of a lower cost of living. His father, a German immigrant, was a mostly unemployed millworker who subscribed to a stern and narrow Roman Catholicism. His mother’s gentle and compassionate outlook sprang from her Czech Mennonite background." };

int main()
{
	std::istringstream iss(inputString, std::istringstream::in);

	int count{ 0 };
	std::string word;
	while (iss >> word)
	{
		++count;
	}
	std::cout << "Text contains " << count << " words" << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}