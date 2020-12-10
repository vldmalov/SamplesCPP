#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person {

	Person(const std::string& firstName, const std::string& lastName, int birthYear)
		: _firstName(firstName)
		, _lastName(lastName)
		, _birthYear(birthYear)
	{}

	friend bool operator<(const Person& lhs, const Person& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
	std::string _firstName;
	std::string _lastName;
	short _birthYear;
};

bool operator<(const Person& lhs, const Person& rhs)
{
	return lhs._birthYear < rhs._birthYear;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << person._firstName << " " << person._lastName << ". Birth year = " << person._birthYear;
	return os;
}

int main()
{
	std::vector<Person> scientists;

	scientists.push_back(Person("Mikhail", "Lomonosov", 1711));
	scientists.push_back(Person("Andrei", "Alexandrescu", 1969));
	scientists.push_back(Person("Alexander", "Bell", 1847));
	scientists.push_back(Person("Bjarne", "Stroustrup", 1950));
	scientists.push_back(Person("Isaac", "Newton", 1642));

	std::cout << "Scientists list: " << std::endl;
	for (const Person& s : scientists)
	{
		std::cout << s << std::endl;
	}

	std::sort(scientists.begin(), scientists.end());

	std::cout << "\nSorted scientists list: " << std::endl;
	for (const Person& s : scientists)
	{
		std::cout << s << std::endl;
	}

	std::cin.ignore();
	std::cin.get();
}