#include <iostream>

class IntWrapper
{
public:
    explicit IntWrapper(int val)
    :m_val(val)
    {
        std::cout << "IntWrapper. Constructor has been called" << std::endl;
    }

    IntWrapper& operator++()
    {
        ++m_val;
        return *this;
    }

    const IntWrapper operator++(int)
    {
        IntWrapper tmp(*this);
        ++(*this);
        return tmp;
    }

    friend std::ostream& operator<<(std::ostream& os, const IntWrapper& val);

private:
    int m_val;
};

std::ostream& operator<<(std::ostream& os, const IntWrapper& val)
{
    os << val.m_val;
    return os;
}

int main()
{
    IntWrapper val(7);
    std::cout << "First  output: " << ++val << std::endl;
    std::cout << "Second output: " << val++ << std::endl;
    std::cout << "3rd    output: " << val << std::endl;
    std::cout << "4rd    output: " << ++++val << std::endl;
    //++(val++); // cant increment const T value
    return 0;
}