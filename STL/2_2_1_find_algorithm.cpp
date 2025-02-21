#include <iostream>
#include <array>

const int ARRAY_SIZE = 5;
const char CH_ARRAY[ARRAY_SIZE] = {'a', 'b', 'c', 'd', 'e'};

int main() 
{
    const char* find_ch = std::find(&CH_ARRAY[0], &CH_ARRAY[ARRAY_SIZE], 'b');
    std::cout << "C CHAR ARRAY\n";
    std::cout << "found char = " << *find_ch << "\n";
    std::cout << "next char = " << *(find_ch + 1) << "\n";
    

    std::cout << "CPP CHAR ARRAY\n";
    std::array<char, ARRAY_SIZE> array = {'a', 'b', 'c', 'd', 'e'};
    std::array<char, ARRAY_SIZE>::const_iterator found_it = std::find(begin(array), end(array), 'd');
    if(found_it != array.end()) {
        std::cout << "Symbol found. " << *found_it << "\n";
        std::cout << "Next symbol is " << *(++found_it) << std::endl;
    }

    return 0;
}
