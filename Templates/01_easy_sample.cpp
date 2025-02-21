#include "iostream"

template<typename T>
T min(const T& a, const T& b)
{
    return a < b ? a : b;
}

// 1. По к-ву символов в строке. Явная специализация шаблона
// template<>
// std::string min<>(const std::string& a, const std::string& b)
// {
//     return a.size() < b.size() ? a : b;
// }

int main() {

    std::cout << ::min(12, -34) << "\n";
    std::cout << ::min(12.32, -34.05) << "\n";

    std::cout << ::min<double>(12.32, 10) << "\n";

    std::cout << ::min<std::string>("Max", "Alex") << "\n";

    std::cin.ignore();
    std::cin.get();
}