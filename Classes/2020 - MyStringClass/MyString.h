#pragma once
#include <ostream>

// Интерфейс
// Данные

class MyString final {

public:
    MyString();
    ~MyString();

    MyString(const char* cStr);
    MyString(const MyString& other);

    MyString& operator=(const MyString& other);

    unsigned int GetSize() const;
    bool IsEmpty() const;

    char& operator[](size_t idx);
    const char& operator[](size_t idx) const;

    MyString& operator+=(const MyString& rhs);

private:
    void Clean();

private:
    char* _data = nullptr;
    unsigned int _size = 0;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};

MyString operator+(const MyString& lhs, const MyString& rhs);

bool operator==(const MyString& lhs, const MyString& rhs);

std::ostream& operator<<(std::ostream& os, const MyString& str);