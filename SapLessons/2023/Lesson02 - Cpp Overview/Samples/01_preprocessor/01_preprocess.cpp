#include <iostream>

// #define UNUSED_CODE_BLOCK
#define DEBUG

int main()
{ 
#ifdef UNUSED_CODE_BLOCK
    std::string str = 25;
#endif

#ifdef DEBUG
    std::cout << "Debug output" << std::endl;
    std::cout << "Circumference of circle " << circumferenceOfCircle << std::endl;
#else
    std::cout << "Release output" << std::endl;
#endif
}
