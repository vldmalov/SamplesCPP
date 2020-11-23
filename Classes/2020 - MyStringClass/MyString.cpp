#include "MyString.h"

#include <iostream>
#include <cstring>

MyString::MyString()
{
    std::cout << "MyString Default Constructor" << std::endl;
}

MyString::~MyString()
{
    std::cout << "MyString Destructor" << std::endl;
    Clean();
}

void MyString::Clean()
{
    delete [] _data;
    _size = 0;
}

MyString::MyString(const char* cStr)
{
    std::cout << "MyString Constructor from C String" << std::endl;
    
    _size = strlen(cStr);
    if(_size > 0)
    {
        _data = new char[_size + 1];
        strcpy_s(_data, _size + 1, cStr);
    }
}

MyString::MyString(const MyString& other)
{
    std::cout << "MyString Copy Constructor" << std::endl;

    _size = other._size;
    if(_size > 0)
    {
        _data = new char[_size + 1];
        strcpy_s(_data, _size + 1, other._data);
    }
}

MyString& MyString::operator=(const MyString& other)
{
    std::cout << "MyString Operator=" << std::endl;

    if(this == &other) {
        return *this;
    }

    Clean();
    _size = other._size;
    if(_size > 0)
    {
        _data = new char[_size + 1];
        strcpy_s(_data, _size + 1, other._data);
    }

    return *this;
}


unsigned int MyString::GetSize() const
{
    return _size;
}

bool MyString::IsEmpty() const
{
    return GetSize() == 0;
}

char& MyString::operator[](size_t idx)
{
    return _data[idx];
}

const char& MyString::operator[] (size_t idx) const
{
    return _data[idx];
}

MyString& MyString::operator+=(const MyString& rhs)
{
    if (rhs.IsEmpty()) {
        return *this;
    }

    char* newData = new char[_size + rhs._size + 1];
    strcpy_s(newData, _size + 1, _data);
    strcpy_s(newData + _size, rhs._size + 1, rhs._data);
    std::swap(_data, newData);
    delete[] newData;
    _size += rhs._size;

    return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString result = lhs;
    result += rhs;

    return result;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    if (lhs.GetSize() != rhs.GetSize()) {
        return false;
    }

    for (size_t idx = 0; idx < lhs.GetSize(); ++idx) {
        if (lhs[idx] != rhs[idx]) {
            return false;
        }
    }

    return true;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    // for(size_t idx = 0; idx < str.GetSize(); ++idx)
    // {
    //     os << str[idx];
    // }
    if (!str.IsEmpty()) {
        os << str._data;
    }

    return os;
}