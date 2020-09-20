#include <iostream>
#include <list>

class WrappedInt {
public:
    WrappedInt(int value) : m_value(value) {};
    
    WrappedInt& operator++() {
        
        ++m_value;
        return *this;
    }
    
    const WrappedInt operator++(int) {
        WrappedInt result = *this;
        
        operator++();
        
        return result;
    }
    
    friend std::ostream& operator<<(std::ostream &os, const WrappedInt& item);
    
private:
    int m_value;
};

std::ostream& operator<<(std::ostream &os, const WrappedInt& item) {
    
    os << item.m_value;
    return os;
}

int main()
{
    int a(0);
    a++;
    std::cout << a << std::endl;
    ++(++a);
    std::cout << a << std::endl;
//    ++(a++);
//    std::cout << a << std::endl;
    
    std::cout << "----- WrappedInt -----" << std::endl;
    WrappedInt b(0);
    b++;
    std::cout << b << std::endl;
    ++(++b);
    std::cout << b << std::endl;
//    ++(b++);  // see const WrappedInt operator++(int)
//    std::cout << b << std::endl;
}