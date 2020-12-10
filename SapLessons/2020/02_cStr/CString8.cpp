#include <cstring>
#include <iostream>

int main()
{
	char sourceStr[] = "Simple plain string";

	char* foundStr = strstr(sourceStr, "plain");
	if(foundStr != NULL) {
		const int foundPos = foundStr - sourceStr + 1;
		std::cout << "Found! It started from " << foundPos << " position\n";

		std::cout << "Print result: " << foundStr << "\n";

		char* pStr = sourceStr + 15;
		std::cout << "Print result: " << pStr << "\n";
	}
	else
	{
		std::cout << "Substring hasn't found in source string"; 
	}
}