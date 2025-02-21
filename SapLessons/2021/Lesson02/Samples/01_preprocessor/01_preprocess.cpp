#include <iostream>
#define PI 3.1415
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define SQR(x) (x*x)

// #define WRONG_CODE_BLOCK

// 1. Директивы препроцессора
// 2. Результат работы препроцессора (ед. трансляции)
// 3. Особенности макрасов на примере SQR(4 + 1), ++val
// 4. Показать работу ifdef/else блоков и применения
// 5. Влияние на компиляцию на примере WRONG_CODE_BLOCK
// 6. Include guards
int main()
{
    [[maybe_unused]]int testValue{123};
    
#ifdef DEBUG
    std::cout << "Debug output" << std::endl;
    std::cout << "Test value is " << testValue << std::endl;
#else
    std::cout << "Release output" << std::endl;
#endif

#ifdef WRONG_CODE_BLOCK
    std::string str = 25;
#endif

    std::cout << "MIN(3, 7) is " << MIN(3, 7) << std::endl;
    //std::cout << "SQR(4 + 1) = " << SQR(4 + 1) << std::endl;

    //int val{ 2 };
    //std::cout << "SQR(++val) = "<< SQR(++val) << std::endl;
    return 0;
}
