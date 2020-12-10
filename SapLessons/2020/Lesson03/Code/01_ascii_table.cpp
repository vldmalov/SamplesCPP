#include <iostream>
#include <fstream>

// Форматирование
// Перегрузка функций
// Вынос констант
// Вывод в файл
// Вывод в файл/на консоль. Перегрузка
// Вывод в строку

const int OUTPUT_FIELD_WIDTH = 12;

void PrintAsciiTable(std::ostream& os, unsigned char firstSymbol, unsigned char lastSymbol)
{
   if(firstSymbol > lastSymbol) {
        std::cerr << "First symbol code " << (int)firstSymbol << " more than last one " << (int)lastSymbol << std::endl;
        return;
    }

    os << std::left;
    os.width(OUTPUT_FIELD_WIDTH); os << "Dec"; 
    os.width(OUTPUT_FIELD_WIDTH); os << "Hex";
    os.width(OUTPUT_FIELD_WIDTH); os << "Char" << std::endl;

    do {
        const int symbCode = static_cast<int>(firstSymbol);
        os.width(OUTPUT_FIELD_WIDTH); os << std::showbase << std::dec << symbCode;
        os.width(OUTPUT_FIELD_WIDTH); os << std::showbase << std::hex << symbCode;
        os.width(OUTPUT_FIELD_WIDTH); os << firstSymbol << std::endl;
        ++firstSymbol;
    }
    while(firstSymbol < lastSymbol);
}

void PrintAsciiTable(std::ostream& os, unsigned char symbol)
{
   PrintAsciiTable(os, symbol, symbol);
}

int main()
{
    //PrintAsciiTable('a', 'z');
    //PrintAsciiTable('A', 'z');
    //PrintAsciiTable('Z');

    //PrintAsciiTable(0, 128);
     //PrintAsciiTable(128, 255);

    std::ofstream ofs("AsciiTable.txt");
    PrintAsciiTable(ofs, 'a', 'z');
    PrintAsciiTable(std::cout, 'a', 'z');
}