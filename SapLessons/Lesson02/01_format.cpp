#include <iostream>
#include <cmath>
#include <array>

const float  PI_F=3.14159265358979f;

int main()
{
    std::array<int, 9> angles = {
        0, 30, 45, 60, 90, 120, 135, 150, 180
    };

    std::cout.width(10);
    std::cout << std::left << "Angles";
    for(auto angle : angles)
    {
        std::cout.width(5);
        std::cout << std::right << angle << " "; 
    }
    std::cout << std::endl;

    std::cout.width(10);
    std::cout << std::left << "Sin";
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed);
    for(auto angle : angles)
    {
        float angleRad{ PI_F * angle / 180.f };

        std::cout.width(5);
        std::cout << std::right << sin(angleRad) << " "; 
    }
    std::cout << std::endl;
}