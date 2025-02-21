#include "CustomString.h"
#include <iostream>
#include <cstring>

CustomString::CustomString() {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    Clear();
}

CustomString::CustomString(const char* cStr) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    if(!cStr) {
        Clear();
        return;
    }

    _size = strlen(cStr);
    _data = new char[_size + 1];
    memcpy(_data, cStr, _size + 1);
}

CustomString::CustomString(const CustomString& other) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    _size = other._size;
    _data = new char[_size + 1];
    memcpy(_data, other._data, _size + 1);
}

CustomString::CustomString(CustomString&& other) noexcept {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    swap(*this, other);
}

CustomString::~CustomString() {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    delete [] _data;
    // delete [] _data;             // ASAN: Attempting double-free
    // std::cout << _data[0];       // ASAN: Heap-use-after-free
}

CustomString& CustomString::operator=(const CustomString& other) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    CustomString tmp(other);
    swap(*this, tmp);

    return *this;
}

CustomString& CustomString::operator=(CustomString&& other) noexcept {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    swap(*this, other);
    return *this;
}

CustomString& CustomString::operator+=(const CustomString& rhs) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    if (rhs.IsEmpty()) {
        return *this;
    }

    char* newData = new char[_size + rhs._size + 1];
    // char* newData = new char[rhs._size + 1]; // ASAN heap-buffer-overflow
    memcpy(newData, _data, _size);
    memcpy(newData + _size, rhs._data, rhs._size);
    newData[_size + rhs._size] = '\0';

    std::swap(_data, newData);
    delete[] newData;
    _size += rhs._size;

    return *this;
}

char& CustomString::operator[](size_t idx) {
    return _data[idx];
}

const char& CustomString::operator[] (size_t idx) const {
    return _data[idx];
}

bool CustomString::IsEmpty() const {
    return _size == 0;
}

size_t CustomString::GetSize() const {
    return _size;
}

const char* CustomString::GetData() const {
    return _data;
}

void CustomString::Clear() {
    _size = 0;
    _data = new char[1];
    _data[0] = '\0'; //ASAN: Remove this line to get Heap buffer overflow
}

void CustomString::Resize(size_t newSize, char ch) {
    if(newSize > _size) {
        char* newData = new char[newSize + 1];
        memcpy(newData, _data, _size);
        memset(newData + _size, ch, newSize - _size);
        newData[newSize] = '\0';
        std::swap(_data, newData);
        delete [] newData;
    }
    _size = newSize;
}

CustomString operator+(const CustomString& lhs, const CustomString& rhs) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    CustomString result = lhs;
    result += rhs;

    return result;
}


bool operator==(const CustomString& lhs, const CustomString& rhs) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    const size_t size = lhs._size;
    if (size != rhs._size) {
        return false;
    }
    return std::equal(lhs._data, lhs._data + size, rhs._data);
}

bool operator!=(const CustomString& lhs, const CustomString& rhs) {
#ifdef DEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    return !(lhs == rhs);
}

void swap(CustomString& lhs, CustomString& rhs) {
    std::swap(lhs._size, rhs._size);
    std::swap(lhs._data, rhs._data);
}

std::ostream& operator<<(std::ostream& os, const CustomString& str) {
#ifdef DEBUG
    os << "\"" << str.GetData() << "\" " << "(size : " << str.GetSize() << ")";
#else
    os << str.GetData();
#endif
    return os;
}