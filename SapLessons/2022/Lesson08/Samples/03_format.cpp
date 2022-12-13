#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

const float PI_F = 3.14159265358979f;

float dumpFunc(float angle)
{
    return angle;
}

float calcSin(float angle)
{
    float angleRad{ PI_F * angle / 180.f };
    return sin(angleRad);
}

float calcCos(float angle)
{
    float angleRad{ PI_F * angle / 180.f };
    return cos(angleRad);
}

void printValues(   const std::vector<int>& values,
                    const std::string& title,
                    int precision,
                    const std::function<float(float)>& transformFunc)
{
    std::cout.width(10);
    std::cout << std::left << title;
    std::cout.precision(precision);

    std::cout.setf(std::ios::fixed); // scientific
    for(auto val : values)
    {
        std::cout.width(5);
        std::cout << std::right << transformFunc(val) << " "; 
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> angles = {
        0, 30, 45, 60, 90, 120, 135, 150, 180
    };

    printValues(angles, "Angles", 0, dumpFunc);
    printValues(angles, "Sin", 2, calcSin);
    printValues(angles, "Cos", 2, calcCos);
}