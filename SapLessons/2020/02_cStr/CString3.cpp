#include <cstring> 
#include <iostream>

int main() 
{
    char carBrand[10] = "";
    std::cout << "Please, enter your favorite car brand: ";
    std::cin >> carBrand;

    std::cout << "Array  size is " << sizeof(carBrand) << "\n";
    std::cout << "String size is " << strlen(carBrand) << "\n";
}