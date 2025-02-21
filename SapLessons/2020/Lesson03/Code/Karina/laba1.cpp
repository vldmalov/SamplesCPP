#include <iostream>
#define FIELD_OUTPUT 7

void PrintAsciiTable(unsigned char firstSymbol, unsigned char lastSymbol)
{
	if (firstSymbol > lastSymbol)
	{
		std::cerr << "First Symbol code " << (int)firstSymbol << "more than last one " << (int)lastSymbol << std::endl;
		return;
	}		

	unsigned char startSymbol = firstSymbol;
	std::cout << std::left;

	for (int i = 0; i < 3; i++)
	{
		firstSymbol = startSymbol;
		switch (i)
		{
		case 0: std::cout.width(FIELD_OUTPUT); std::cout << "Dec";
			do 
			{
				std::cout.width(FIELD_OUTPUT); std::cout << std::showbase << std::dec << int(firstSymbol);
			} while (firstSymbol++ < lastSymbol);
			std::cout << "" << std::endl;
			break;

		case 1: std::cout.width(FIELD_OUTPUT); std::cout << "Hex";
			do
			{
				std::cout.width(FIELD_OUTPUT); std::cout << std::showbase << std::hex << int(firstSymbol);
			} while (firstSymbol++ < lastSymbol);
			std::cout << "" << std::endl;
			break;

		case 2: std::cout.width(FIELD_OUTPUT); std::cout << "Char";
			do
			{
				std::cout.width(FIELD_OUTPUT); std::cout << firstSymbol;
			} while (firstSymbol++ < lastSymbol);
			std::cout << "" << std::endl;
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	PrintAsciiTable(45, 50);
	getchar();
	return 0;
}
