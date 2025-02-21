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
        _data = new char[_size];
        memcpy(_data, cStr, _size);
    }
}

MyString::MyString(const MyString& other)
{
    std::cout << "MyString Copy Constructor" << std::endl;

    _size = other.GetSize();
    if(_size > 0)
    {
        _data = new char[_size];
        memcpy(_data, other._data, _size);
    }
}

MyString::MyString(MyString&& other) noexcept
{
    std::cout << "MyString Move Constructor" << std::endl;
    swap(*this, other);
}

MyString& MyString::operator=(const MyString& other)
{
    std::cout << "MyString Copy Assignment" << std::endl;

    MyString tmp(other);
    swap(*this, tmp);

    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    std::cout << "MyString Move Assignment" << std::endl;
    swap(*this, other);

    return *this;
}

size_t MyString::GetSize() const
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

const char* MyString::begin() const {
    return _data;
}

const char* MyString::end() const {
    return _data + _size;
}

MyString& MyString::operator+=(const MyString& rhs)
{
    std::cout << "MyString Operator+=" << std::endl;
    if (rhs.IsEmpty()) {
        return *this;
    }

    char* newData = new char[_size + rhs._size];
    memcpy(newData, _data, _size);
    memcpy(newData + _size, rhs._data, rhs._size);
    std::swap(_data, newData);
    delete[] newData;
    _size += rhs._size;

    return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    std::cout << "MyString Operator+" << std::endl;
    MyString result = lhs;
    result += rhs;

    return result;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    std::cout << "MyString Operator==" << std::endl;
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

void swap(MyString& lhs, MyString& rhs)
{
    std::swap(lhs._size, rhs._size);
    std::swap(lhs._data, rhs._data);
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    if (!str.IsEmpty()) {
        std::copy(str.begin(), str.end(), std::ostream_iterator<char>(os, ""));
    }
    return os;
}