#include <iostream>

#define PI 3.1415f
#define SQR(x) (x*x)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// #define UNUSED_CODE_BLOCK
// #define DEBUG

int main()
{ 
#ifdef UNUSED_CODE_BLOCK
    std::string str = 25;
#endif

    std::cout << "SQR(5) = " << SQR(5) << std::endl;
    std::cout << "SQR(5) = " << SQR(3 + 2) << std::endl;
    std::cout << "MIN(3, 7) is " << MIN(3, 7) << std::endl;

    const float radius = 12.5f;
    const float circumferenceOfCircle = 2.f * PI * radius;
#ifdef DEBUG
    std::cout << "Debug output" << std::endl;
    std::cout << "Circumference of circle " << circumferenceOfCircle << std::endl;
#else
    std::cout << "Release output" << std::endl;
#endif
}
