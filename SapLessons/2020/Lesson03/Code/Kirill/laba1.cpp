#include <iostream>
#include <cstring>

const int OUTPUT_FIELD_WIDTH = 8;

void PrintAsciiTable(unsigned char firstSymbol, unsigned char lastSymbol)
{
	if (firstSymbol > lastSymbol)
	{
		std::cerr << "First Symbol code " << (int)firstSymbol << "more than last one " << (int)lastSymbol << std::endl;
		return;
	}		

	unsigned char startSymbol = firstSymbol;
	std::cout << std::left;

	std::cout.width(OUTPUT_FIELD_WIDTH); std::cout << "Dec";
	do
	{
		std::cout.width(OUTPUT_FIELD_WIDTH); std::cout << std::showbase << std::dec << int(firstSymbol);
	} while (firstSymbol++ < lastSymbol);
	std::cout << "" << std::endl;

	firstSymbol = startSymbol;
	std::cout.width(OUTPUT_FIELD_WIDTH); std::cout << "Hex";
	do
	{
		std::cout.width(OUTPUT_FIELD_WIDTH); std::cout << std::showbase << std::hex << int(firstSymbol);
	} while (firstSymbol++ < lastSymbol);
	std::cout << "" << std::endl;

	firstSymbol = startSymbol;
	std::cout.width(OUTPUT_FIELD_WIDTH); std::cout << "Char";
	do
	{
		std::cout.width(OUTPUT_FIELD_WIDTH); std::cout << firstSymbol;
	} while (firstSymbol++ < lastSymbol);
	std::cout << "" << std::endl;

}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		std::cerr << "Please enter a correct range!" << std::endl;
		return 1;
	}

	PrintAsciiTable(atoi(argv[1]), atoi(argv[2]));
	getchar();
	return 0;
}