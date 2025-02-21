#pragma once
#include <iosfwd>

class CustomString final {
public:
    CustomString();
    CustomString(const char* cStr);
    CustomString(const CustomString& other);
    CustomString(CustomString&& other) noexcept;

    ~CustomString();

    CustomString& operator=(const CustomString& other);
    CustomString& operator=(CustomString&& other) noexcept;

    CustomString& operator+=(const CustomString& rhs);

    char& operator[](size_t idx);
    const char& operator[](size_t idx) const;

    bool IsEmpty() const;
    size_t GetSize() const;
    const char* GetData() const;

    void Clear();
    void Resize(size_t newSize, char ch = ' ');

private:
    char* _data{ nullptr };
    size_t _size{ 0 };

    friend void swap(CustomString& lhs, CustomString& rhs);
    friend std::ostream& operator<<(std::ostream& os, const CustomString& str);
    friend bool operator==(const CustomString& lhs, const CustomString& rhs);
};

CustomString operator+(const CustomString& lhs, const CustomString& rhs);
bool operator==(const CustomString& lhs, const CustomString& rhs);
bool operator!=(const CustomString& lhs, const CustomString& rhs);
std::ostream& operator<<(std::ostream& os, const CustomString& str);

void swap(CustomString& lhs, CustomString& rhs);