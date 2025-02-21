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
#ifdef MAC_OS
	// Some platform-depending code..
	std::cout << "Mac OS platform specific output" << std::endl;
#else
	std::cout << "Another platform output" << std::endl;
	std::cout << "By the way, Pi = " << PI << std::endl;
#endif

#ifdef WRONG_CODE_BLOCK
	std::string str = 25;
#endif

	std::cout << "MIN(3, 7) is " << MIN(3, 7) << std::endl;
	std::cout << SQR(4 + 1) << std::endl;

	//int val{ 2 };
	//std::cout << SQR(++val) << std::endl; 
	return 0;
}