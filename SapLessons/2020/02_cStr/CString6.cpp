#include <cstring>
#include <iostream>

const char PASSWORD[] = "a371_Z";
const int MAX_ATT_COUNT = 3;

int main()
{
	bool isSuccess{false};

	char userInput[128];
	int attemptCount {0};
	do {
		std::cout << "Please, enter password: ";
		std::cin >> userInput;

		isSuccess = strcmp(PASSWORD, userInput) == 0;
	}
	while(!isSuccess && ++attemptCount < MAX_ATT_COUNT );

	if(isSuccess) {
		std::cout << "Password has been accepted!" << std::endl;
	} else {
		std::cout << "Access denied!" << std::endl;
	}
}