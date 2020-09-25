#include <iostream>

#define PI 3.1415d
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
#ifdef MAC_OS
	// Some platform-depending code..
	std::cout << "Mac OS platform specific output" << std::endl;
#else
	std::cout << "Another platform output" << std::endl;
	std::cout << "By the way, Pi = " << PI << std::endl;
#endif
	std::cout << "MIN(3, 7) is " << MIN(3, 7) << std::endl;
	return 0;
}