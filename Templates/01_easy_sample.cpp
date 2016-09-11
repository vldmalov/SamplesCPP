#include "iostream"

template<typename T>
T min(const T& a, const T& b)
{
    return a < b ? a : b;
}

int main() {

    std::cout << "Lounch main function \n";
    std::cout << ::min(12, -34) << "\n";
    std::cout << ::min(12.32, -34.05) << "\n";
    std::cout << ::min<std::string>("Max", "Alexis") << "\n";

    std::cout << ::min<double>(12.32, 10) << "\n";

    return 0;
}