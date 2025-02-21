#include <cstring> 
#include <iostream>  

int main() 
{
    char cstr[] = "I'm Plain C string!"; // 19 symbols
    cstr[7] = 'y';
    cstr[8] = 'i';
    cstr[9] = 'n';
    cstr[10] = 'g';
    cstr[11] = '\0';

    std::cout << cstr << std::endl;
    std::cout << "My size is " << strlen(cstr) << "\n";
    std::cout << "But my array size is " << sizeof(cstr) << "\n";
}