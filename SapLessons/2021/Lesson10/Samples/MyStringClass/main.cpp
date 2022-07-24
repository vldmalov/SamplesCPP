#include <iostream>
#include <algorithm>
#include <cassert>
#include "MyString.h"

void CreateDefaultMyString() {
    MyString str;
    std::cout << "Empty str = \"" << str << "\"; size = " << str.GetSize() << '\n';
}

void CreateMyStringFromCString() {
    char c_str[] = "A rose by any other name would smell as sweet";
    MyString str(c_str);
    std::cout << "Filled str = \"" << str << "\"; size = " << str.GetSize() << '\n';
}

void CopyMyString() {
    MyString srcStr("Discover the impact IBM has on everyone, everyday");
    MyString dstStr(srcStr);
    std::cout << srcStr << '\n' << dstStr << '\n';
    srcStr = MyString("Another text");
    std::cout << srcStr << '\n' << dstStr << '\n';
}

void ConcatMyStrings() {
    MyString str("One ");
    str += MyString("More ");
    str += MyString("Little Thing");
    std::cout << "Concatinated string = " << str << '\n';
}

void ConcatMyStrings2() {
    MyString str = MyString("One ") + MyString("More ") + MyString("Little Thing");
    std::cout << "Concatinated string = " << str << '\n';
}

void CompareMyStrings() {
    MyString str1{ "My string" };
    MyString str2{ "My String" };
    std::cout << "Is strings the same: " << std::boolalpha << (str1 == str2) << std::endl;
}

void MyStringsAlgo() {
    MyString str("Another Brick in the Wall");
    const char symbol = 'i';

    size_t result = std::count_if(str.begin(), str.end(), [symbol](const char ch) {
        return ch == symbol;
        });
    assert(result == 2);
}

void MyStringsMoveSematic() {
    MyString str("Another Brick in the Wall");
    MyString str2 = std::move(str);
    std::cout << str << '\n' << str2 << '\n';
    str = std::move(str2);
    std::cout << str << '\n' << str2 << '\n';
}

int main()
{
    std::cout << "Main start" << std::endl;

    CreateDefaultMyString();
    std::cout << std::endl;

    CreateMyStringFromCString();
    std::cout << std::endl;

    CopyMyString();
    std::cout << std::endl;

    ConcatMyStrings();
    std::cout << std::endl;

    ConcatMyStrings2();
    std::cout << std::endl;

    CompareMyStrings();
    std::cout << std::endl;

    MyStringsAlgo();
    std::cout << std::endl;

    MyStringsMoveSematic();
    std::cout << std::endl;

    std::cout << "Main end" << std::endl;
}