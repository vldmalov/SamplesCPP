#include<iostream>

void readRange(unsigned char& x, unsigned char& y)
{
    do
    {
        std::cout << "First char:" << std::endl;
        std::cin >> x;

        std::cout << "Second char:" << std::endl;
        std::cin >> y;

        if (x > y)
        {
            std::cout << "Invalid range has been entered!" << std::endl;
            std::cout << "First entered symbol is " << x << " (code = " << (int)x << ")" << std::endl;
            std::cout << "Last entered symbol is " << y << " (code = " << (int)y << ")" << std::endl;
            std::cout << "Please, enter correct range!" << std::endl;     
        }
    }
    while(x > y);
}

void printRange(unsigned char from, unsigned char to, const std::string& title, bool isInt)
{
    std::cout << title;
    for (unsigned char i = from; i <= to; i++)
    {
        std::cout.width(5);
        if(isInt) {
            std::cout << int(i) << std::right;
        }
        else {
            std::cout << i << std::right;
        }  
    }
    std::cout << std::endl;
}

int main()
{
    unsigned char x;
    unsigned char y;
    readRange(x, y);

    unsigned char i=0;

    printRange(x, y, "char ", false);
    std::cout << std::dec;
    printRange(x, y, "dec  ", true);
    std::cout << std::hex;
    printRange(x, y, "hex  ", true);
    std::cout << std::oct;
    printRange(x, y, "oct  ", true);

    return 0;
}