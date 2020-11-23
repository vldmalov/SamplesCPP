#include <iostream>
#include "MyString.h"

void PrintMyString(const MyString& str, const std::string& title) {
    std::cout << title << " = \"" << str << "\"; size = " << str.GetSize() << std::endl;
}

void CreateDefaultMyString() {
    MyString str;
    PrintMyString(str, "CreateDefaultMyString. str");
}

/*void CreateMyStringFromCString() {
    char c_str[] = "A rose by any other name would smell as sweet";
    MyString str(c_str);
    PrintMyString(str, "CreateMyStringFromCString. str");
}

void CopyMyString() {
    MyString srcStr("Discover the impact IBM has on everyone, everyday");
    MyString dstStr(srcStr);
    PrintMyString(srcStr, "CopyMyString srcStr");
    PrintMyString(dstStr, "CopyMyString dstStr");

    srcStr = MyString("Another text");
    PrintMyString(srcStr, "CopyMyString srcStr");
    PrintMyString(dstStr, "CopyMyString dstStr");
}

void ConcatMyStrings() {
    MyString str("One ");
    str += MyString("More ");
    str += MyString("Little Thing");

    PrintMyString(str, "ConcatMyStrings result");
}

void ConcatMyStrings2() {
    MyString str;
    str = MyString("One ") + MyString("More ") + MyString("Little Thing");

    PrintMyString(str, "ConcatMyStrings2 result");
}

void CompareMyStrings() {
    MyString str1 = "My string";
    MyString str2 = "My String";
    std::cout << "Is strings the same: " << std::boolalpha << (str1 == str2) << std::endl;
}*/

int main()
{
   std::cout << "Main start" << std::endl;

    CreateDefaultMyString();
    //CreateMyStringFromCString();
    //CopyMyString();
    //ConcatMyStrings();
    //ConcatMyStrings2();
    //CompareMyStrings();

    std::cout << "Main end" << std::endl;
}