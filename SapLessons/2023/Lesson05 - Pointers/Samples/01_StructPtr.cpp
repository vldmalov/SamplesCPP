#include<iostream>

struct vector2 {
    vector2(float _x, float _y)
    : x(_x), y(_y) {}

    float x{ 0.f };
    float y{ 0.f };
};

int main() {
    vector2 vec {1.f, -0.5f};
    vector2* pVec = &vec;

    std::cout << "Vec size:     " << sizeof(vec) << std::endl;
    std::cout << "Vec address:  " << pVec << std::endl;
    std::cout << "Next address: " << ++pVec << std::endl;
    std::cout << "Next address: " << ++pVec << std::endl;
}