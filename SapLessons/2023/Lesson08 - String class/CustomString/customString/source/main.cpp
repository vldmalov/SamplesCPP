#include <iostream>
#include <algorithm>
#include <cassert>

#include "CustomString.h"

void CreateDefaultCustomString() {
    CustomString str;
    std::cout << &str << " " << sizeof(str) << std::endl;
    std::cout << str << std::endl;
}

void CreateCustomStringFromCString() {
    char cStr[] = "A rose by any other name would smell as sweet";

    CustomString str(cStr);
    std::cout << str << std::endl;
}

void CopyCustomString() {
    CustomString srcStr("An initial text here..");
    CustomString dstStr(srcStr);
    std::cout << srcStr << std::endl;
    std::cout << dstStr << std::endl;

    dstStr = CustomString("A brand new updated text.");
    std::cout << dstStr << std::endl;
}

void CompareCustomStrings() {
    CustomString str1{ "String value" };
    CustomString str2{ "String value" };

    const bool stringsAreEqual = str1 == str2;
    std::cout << "Strings are equal: " << std::boolalpha << stringsAreEqual << std::endl;
}

void ConcatCustomStrings() {
    CustomString str1("One");
    CustomString str2("More ");
    CustomString str3("Little Thing");

    CustomString resultStr = str1 + " " + str2;
    resultStr += str3;

    std::cout << "Resulted string: " << resultStr << std::endl;
}

void CustomStringsMoveSematic() {
    CustomString str1("A rose by any other name would smell as sweet");
    CustomString str2 = std::move(str1);
    //std::cout << str1 << std::endl; // SEGV signal is sent by the OS to inform a process that it has attempted an illegal memory access
    std::cout << str2 << std::endl;
    str1 = std::move(str2);
    std::cout << str1 << std::endl;
    //std::cout << str2 << std::endl; // SEGV

}

void CustomStringsResize() {
    CustomString str("Custom String");
    std::cout << str << std::endl;
    str.Resize(6);
    std::cout << str << std::endl;
    str.Resize(10, 'a');
    std::cout << str << std::endl;
}

void CustomStringsAccessByIndex() {
    CustomString str("Custom String");
    std::cout << str << std::endl;
    str[7] = 's';
    std::cout << str << std::endl;


    //str[20] = 's';       //ASAN: Heap buffer overflow
}

void CustomStringsGetData() {
    const char* cStr{ nullptr };

    CustomString str("Custom String");
    cStr = str.GetData();
    std::cout << "cStr: " << cStr << ", size: " << strlen(cStr) << std::endl;


    // ASAN: Heap use after free
     std::cout << "cStr: " << cStr << ", size: " << strlen(cStr) << std::endl;
}

// Classes
// Configurations (optimisations / debug info)
// Project file
// ASAN

int main()
{
//    CreateDefaultCustomString();
//    CreateCustomStringFromCString();
//    CopyCustomString();
//    CompareCustomStrings();
//    ConcatCustomStrings();
//    CustomStringsMoveSematic();
//    CustomStringsResize();
    CustomStringsAccessByIndex();
//    CustomStringsGetData();
}