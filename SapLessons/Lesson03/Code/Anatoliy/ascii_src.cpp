#include<iostream>
using namespace std;

int main()
{
    unsigned char x;
    unsigned char y;

    unsigned char i=0, j=0;
    double f=0;

    for (f = 0; f < 1;) 
    {
        std::cout << "First char:" << endl;
        std::cin >> x;

        std::cout << "Second char:" << endl;
        std::cin >> y;

        if (x > y)
        {
            std::cout << "Error. Need new char! " << endl;
        }
        else
        {
            f = 1;      
        }
    }

    j = y;

    std::cout << "dec ";
    for (i = x; i <= j; i++)
    {
       
        std::cout.width(5);
        std::cout << dec << int(i)<<right;
        
    }

    j = y;

    std::cout << endl;
    std::cout << "hex ";
    for (i = x; i <= j; i++)
    {
        std::cout.width(5);
        std::cout << hex << int(i) << right;

    }

    j = y;

    std::cout << endl;
    std::cout << "oct ";
    for (i = x; i <= j; i++)
    {
        std::cout.width(5);
        std::cout << oct << int(i) << right;

    }

    j = y;

    std::cout << endl;
    std::cout << "char";
    for (i = x; i <= j; i++)
    {
        std::cout.width(5);
        std::cout << i << right;

    }

    return 0;
}