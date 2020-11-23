// Test example
// Create simple class & implement next functions:
// constructor, copy constructor, operator= via swap idiom
#include <iostream>

class MyString
{
public:
    explicit MyString(const char*);
    MyString(const MyString& str);
    ~MyString();
    
    MyString& operator=(const MyString& str);
    
    friend std::ostream& operator<<(std::ostream& os, const MyString& val);
    friend void swap(MyString& lhs, MyString& rhs);
    
private:
    char*    m_buff;
    size_t   m_size;
};

MyString::MyString(const char* source_str)
: m_buff(nullptr)
{
    std::cout << "MyString constructor" << std::endl;
    
    m_size = strlen(source_str);
    if(!m_size) {
        return;
    }
    
    m_buff = new char[m_size];
    for(unsigned i = 0; i < m_size; ++i) {
        *(m_buff + i) = *(source_str + i);
    }
}

MyString::MyString(const MyString& str)
: m_buff(nullptr)
{
    std::cout << "MyString copy constructor" << std::endl;
    
    m_size = str.m_size;
    if(!m_size) {
        std::cout << "Input string is empty" << std::endl;
        return;
    }
    
    m_buff = new char[m_size];
    for(unsigned i = 0; i < m_size; ++i) {
        *(m_buff + i) = *(str.m_buff + i);
    }
}

void swap(MyString& lhs, MyString& rhs)
{
    std::swap(lhs.m_size, rhs.m_size);
    std::swap(lhs.m_buff, rhs.m_buff);
}

MyString& MyString::operator=(const MyString& str)
{
    MyString tmp(str);
    swap(*this, tmp);
    
    return *this;
}

MyString::~MyString()
{
    std::cout << "My String was been destroyed" << std::endl;
    delete [] m_buff;
    m_size = 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& val)
{
    for(unsigned i = 0; i < val.m_size; ++i) {
        os << val.m_buff[i];
    }
    
    return os;
}

int main()
{
    MyString str1("My first string");
    std::cout << "My first string seems like this: " << str1 << std::endl;
    MyString str2 = str1;
    std::cout << "My first string after copy " << str1 << std::endl;
    std::cout << "My second string after copy " << str2 << std::endl;
    str2 = MyString("Change my second string value");
    std::cout << "My second string after assignin new value: "<< str2 << std::endl;
    
    MyString emptyStr("");
    std::cout << "Empty constructed string: " << emptyStr << std::endl;
    emptyStr = MyString("Not empty now");
    std::cout << "Empty constructed string after changed: " << emptyStr << std::endl;
    
    emptyStr = MyString("");
    std::cout << "Empty constructed string empty again: " << emptyStr << std::endl;

    
    return 0;
}