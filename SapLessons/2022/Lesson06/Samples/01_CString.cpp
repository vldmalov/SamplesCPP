#include <cstring> 
#include <iostream>  

int main() 
{ 
    char cstr[] = "I'm Plain C string!"; // 19 symbols

    std::cout << cstr << std::endl;
    std::cout << "My size is " << strlen(cstr) << "\n";
    std::cout << "But my array size is " << sizeof(cstr) << "\n";
    std::cout << "One symbol size is " << sizeof(cstr[0]) << "\n";
} 