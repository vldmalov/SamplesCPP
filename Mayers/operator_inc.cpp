#include <iostream>

class WrappedInt {
public:
    explicit WrappedInt(int value) : _value(value) {
        std::cout << "WrappedInt has been constructed!" << std::endl;
    };

    WrappedInt& operator++() {
        ++_value;
        return *this;
    }

    const WrappedInt operator++(int) {
        WrappedInt result = *this;
        operator++(); // ++(*this);

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const WrappedInt& item);

private:
    int _value{ 0 };
};

std::ostream& operator<<(std::ostream& os, const WrappedInt& item) {
    os << item._value;
    return os;
}

int main()
{
    WrappedInt val{ 0 };
    val++;
    ++(++val);
    std::cout << "Value is " << val << std::endl;
    //++(val++); // cant increment const T value
}