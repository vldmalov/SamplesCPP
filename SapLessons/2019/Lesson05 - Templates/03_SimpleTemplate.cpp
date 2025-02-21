#include <iostream>
#include <string>

struct Person;

template<typename TYPE_1>
const TYPE_1& GetMin(const TYPE_1& lhs, const TYPE_1& rhs)
{
	return lhs < rhs ? lhs : rhs;
}

const int& GetMin(const int& lhs, const int& rhs)
{
	return lhs < rhs ? lhs : rhs;
}

const Person& GetMin(const Person& lhs, const Person& rhs)
{
	return lhs < rhs ? lhs : rhs;
}

struct Person {

	Person(const std::string& firstName, const std::string& lastName, int birthYear)
		: _firstName(firstName)
		, _lastName(lastName)
		, _birthYear(birthYear)
	{
	}

//private:
	std::string _firstName;
	std::string _lastName;
	short _birthYear;
};

int main()
{
	std::cout << "Min value is " << GetMin(300, 23) << std::endl;

	Person person1("Andrei", "Alexandrescu", 1969);
	Person person2("Bjarne", "Stroustrup", 1950);

	Person minPerson = GetMin(person1, person2);
	//std::cout << minPerson << " " << std::endl;
	
	std::cin.ignore();
	std::cin.get();
}

// 1. Оператор сравнеия. Различные критерии
//bool operator<(const Person& lhs, const Person& rhs)
//{
//	return lhs._birthYear < lhs._birthYear;
//}

// 1.1. Дружественные функции. Инкапсуляция
// friend bool operator<(const Person& lhs, const Person& rhs);

// 2. Вывод результата в поток вывода. Геттеры
// 2.1. Естественный синтаксис вывода

// 3. Оператор вывода в поток
//std::ostream& operator<<(std::ostream& os, const Person& person)
//{
//	os << person._firstName << " " << person._lastName << ". Birth year = " << person._birthYear << std::endl;
//	return os;
//}

//std::cout << "Min value is " << GetMin(person1, person2) << std::endl;