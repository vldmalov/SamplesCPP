#include <iostream>

// Форматирование
// Перегрузка функций
// Вынос констант

// const int OUTPUT_FIELD_WIDTH = 7;

void PrintAsciiTable(unsigned char firstSymbol, unsigned char lastSymbol)
{
    if(firstSymbol > lastSymbol) {
        std::cerr << "First symbol code " << (int)firstSymbol << " more than last one " << (int)lastSymbol << std::endl;
        return;
    }

    std::cout << std::left;
    std::cout.width(7); std::cout << "Dec"; 
    std::cout.width(7); std::cout << "Hex";
    std::cout.width(7); std::cout << "Char" << std::endl;

    do {
        std::cout.width(7); std::cout << std::dec << (int)firstSymbol;
        std::cout.width(7); std::cout << std::showbase << std::hex << (int)firstSymbol;
        std::cout.width(7); std::cout << firstSymbol << std::endl;

        ++firstSymbol;
    }
    while(firstSymbol < lastSymbol);
}

// void PrintAsciiTable(unsigned char symbol)
// {
//     PrintAsciiTable(symbol, symbol);
// }

int main()
{
    PrintAsciiTable('a', 'z');
    // PrintAsciiTable('a', 'Z');
    // PrintAsciiTable('a', 'a');
    // PrintAsciiTable('a');
    // PrintAsciiTable('A', 'z');
    // PrintAsciiTable(0, 128);
    // PrintAsciiTable(128, 255);
}