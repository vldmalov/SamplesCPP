#include <iostream>
#include <vector>

class WrappedInt {
public:

	WrappedInt(int value)
	:_value(value)
	{
		std::cout << "Constructor has been called!\n";
	}

	WrappedInt(const WrappedInt& lhs)
	{
		std::cout << "Copy constructor has been called!\n";
		this->_value = lhs._value;
	}

	~WrappedInt()
	{
		std::cout << "WrappedInt object has been destructed!\n";
	}

private:
	int _value;
};

int main()
{
	std::vector<WrappedInt> userData = { WrappedInt(1), WrappedInt(2), 4, 9, 16, 25, 36 };

	std::cin.ignore();
	std::cin.get();

	return 0;
}

// 4. Передача вектора в функцию по значению, по ссылке и константной ссылке

// и его вместимость. В чем разница, для чего большая вместимость?
// std::cout << "userData capacity = " << userData.capacity() << std::endl;


//std::vector<int> simpleData;
//for (int idx = 0; idx < 100; ++idx)
//{
//	simpleData.push_back(idx % 10);
//	std::cout << "simpleData size = " << simpleData.size() << "; capacity = " << simpleData.capacity() << std::endl;
//}

// 1.1. Резервация памятирвация памяти