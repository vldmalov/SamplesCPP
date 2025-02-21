#pragma once
#include <ostream>

class MyString final {

public:
    MyString();
    ~MyString();

    MyString(const char* cStr);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    size_t GetSize() const;
    bool IsEmpty() const;

    char& operator[](size_t idx);
    const char& operator[](size_t idx) const;

    const char* begin() const;
    const char* end() const;

    MyString& operator+=(const MyString& rhs);

private:
    void Clean();

private:
    char* _data = nullptr;
    size_t _size = 0;

    //friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend void swap(MyString& lhs, MyString& rhs);
};

MyString operator+(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
std::ostream& operator<<(std::ostream& os, const MyString& str);

void swap(MyString& lhs, MyString& rhs);