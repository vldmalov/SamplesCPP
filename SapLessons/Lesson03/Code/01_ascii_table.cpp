#include <iostream>
//#include <fstream>

// Форматирование
// Перегрузка функций
// Вынос констант
// Вывод в файл
// Вывод в файл/на консоль. Перегрузка
// Вывод в строку

// const int OUTPUT_FIELD_WIDTH = 7;

void PrintAsciiTable(/*std::ostream& os,*/ unsigned char firstSymbol, unsigned char lastSymbol)
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
        const int symbolCode = static_cast<int>(firstSymbol);
        std::cout.width(7); std::cout << std::dec << symbolCode;
        std::cout.width(7); std::cout << std::hex << std::showbase << symbolCode;
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

    //std::ofstream ofs("AsciiTable.txt");
    //PrintAsciiTable(ofs, 'a', 'z');
}