// 1) Одним из критериев качества пользовательских типов является совместимость со встроенными
// 2) Конструкторы с одним параметром служат для преобразования типа. Если мы хоти избежать
//    неявного приведения типа (например, при вызове функции), объявляем конструктор с ключевым словом explicit
// 3) operator* должен возвращать константное значение для обеспечения естественного поведения подобно
//    встроенным типам и обеспечения невозможности компиляции следующих выражений a * b = c
#include <iostream>

class WrappedInt
{
public:
    explicit WrappedInt(int val)
    : m_value(val)
    {
        std::cout << "WrappedInt constructor has been called" << std::endl;
    }
    
    ~WrappedInt()
    {
        std::cout << "WrappedInt destructor has been called" << std::endl;
    }
    
    friend const WrappedInt operator*(const WrappedInt& lhs, const WrappedInt& rhs);
    friend std::ostream& operator<<(std::ostream& os, const WrappedInt& val);
    
private:
    int m_value;
};

const WrappedInt operator*(const WrappedInt& lhs, const WrappedInt& rhs)
{
    WrappedInt result(lhs.m_value * rhs.m_value);
    return result;
}

std::ostream& operator<<(std::ostream& os, const WrappedInt& val)
{
    os << val.m_value;
    return os;
}

void someFunction(const WrappedInt& val)
{
    std::cout << val << std::endl;
    return;
}

int main()
{
    WrappedInt a(10), b(32);
    WrappedInt c = a * b;
    
    // Ниже выражение не скомпилируется, из за того, что оператор умножения
    // типа WrappedInt возвращает константное значение
    //a*b = c;
    std::cout << "Result value: " << c << std::endl;
    
    // Вызов ниже не скомпилируется из-за того, что мы запретили неявное преобразование
    // их int в WrappedInt добавив explicit к конструктору с одним параметром int
    // someFunction(12);
    
    return 0;
}