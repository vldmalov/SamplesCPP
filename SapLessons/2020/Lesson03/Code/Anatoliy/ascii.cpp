#include <iostream>
using namespace std;

std::pair<unsigned char, unsigned char> getRange()
{
    std::pair<unsigned char, unsigned char> range;

    do
    {
        cout << "First char:" << endl;
        cin >> range.first;

        cout << "Second char:" << endl;
        cin >> range.second;

        if (range.first > range.second)
        {
            cout << "Invalid range has been entered!" << endl;
            cout << "First entered symbol is " << range.first << " (code = " << (int)range.first << ")" << endl;
            cout << "Last entered symbol is " << range.second << " (code = " << (int)range.second << ")" << endl;
            cout << "Please, enter correct range!" << endl;  
        }
    }
    while(range.first > range.second);

    return range;
}

template<typename TYPE>
void PrintRange(TYPE from, TYPE to, const std::string& title)
{
    cout.width(7); cout << left << title;
    for (TYPE i = from; i <= to; i++)
    {
        cout.width(5);
        cout << right << i;
    }
    cout << endl;
}


int main()
{
    const auto range = getRange();
    const auto x = range.first;
    const auto y = range.second;

    PrintRange(x, y, "char");
    const int xIdx = (int)x;
    const int yIdx = (int)y;
    cout << dec; PrintRange(xIdx, yIdx, "dec");
    cout << hex; PrintRange(xIdx, yIdx, "hex");
    cout << oct; PrintRange(xIdx, yIdx, "oct");

    return 0;
}