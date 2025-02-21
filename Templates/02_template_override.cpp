#include "iostream"

template<typename T>
const T& max(const T& a, const T& b)
{
    return a > b ? a : b;
}

const std::string& max(const std::string& a, const std::string& b)
{
    return a.length() > b.length() ? a : b;
}

int main()
{
    std::cout << "1. max for integer values: " << max(13, 27) << "\n";
    std::cout << "2. max for string values: " << max("Greate Britan", "Jamaica") << "\n";
    std::cout << "3. max for string values: " << max<std::string>("Greate Britan", "Jamaica") << "\n";
    return 0;
}