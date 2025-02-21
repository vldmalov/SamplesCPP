#include <iostream>
#include <cstring>

unsigned int myStrlen(const char* str)
{
    unsigned int len = 0;
    while(*str) {
        ++str;
        ++len;
    }
    return len;
}

bool myStrcmp(const char* str1, const char* str2 ) {
    while(*str1 != '\0' && *str1 == *str2) {
        ++str1;
        ++str2;
    }
    return *str1 == '\0' && *str2 == '\0';
}

void myStrcpy(const char* src, char* dst)
{
    unsigned int i = 0;
    while (*src != '\0')
    {
        dst[i] = *src;
        i++;
        src++;
    }
    dst[i] = '\0';
}

void MyRevert(char* src)
{
    int leftIdx = 0;
    int rightIdx = myStrlen(src) - 1;

    while(leftIdx < rightIdx) {
        std::swap(src[leftIdx++], src[rightIdx--]);
    }
}

void MyRevert(const char* src, char* dst)
{
    int strLen = myStrlen(src);
    dst[strLen] = '\0';

    while(*src) {
        *(dst + strLen - 1) = *src++;
        --strLen;
    }
}

void myStrcat(const char* s1, const char* s2, char* dst)
{
    unsigned int i = 0;
    while (*s1)
    {
        dst[i] = *s1;
        ++s1;
        ++i;
    }
    while (*s2)
    {
        dst[i] = *s2;
        ++s2;
        ++i;
    }
    dst[i] = '\0';
}

int main()
{
    char str[128] = "ABcd12";
    std::cout << "String size: " << myStrlen(str) << std::endl;
    std::cout << "Expected:    " << strlen(str) << std::endl;

    char strCmp1[128] = "ABcd12";
    char strCmp2[128] = "ABcd12";
    char strCmp3[128] = "ABcd13";
    std::cout << "Result of comparing strCmp1 and strCmp2 is " << myStrcmp(strCmp1, strCmp2) << std::endl;
    std::cout << "Result of comparing strCmp1 and strCmp3 is " << myStrcmp(strCmp1, strCmp3) << std::endl;

    char strDst[128];
    MyRevert(str, strDst);
    std::cout << "Reverted string: " << strDst << std::endl;
    std::cout << "Expected:        21dcBA" << std::endl;

    MyRevert(str);
    std::cout << "Reverted string: " << str << std::endl;
    std::cout << "Expected:        21dcBA" << std::endl;
    MyRevert(str);
    std::cout << "Reverted string: " << str << std::endl;
    std::cout << "Expected:        ABcd12" << std::endl;

    char str2[128];
    myStrcpy(str, str2);
    std::cout << "Copied string: " << str2 << std::endl;
    std::cout << "Expected:      ABcd12" << std::endl;

    char strA[128] = "First";
    char strB[128] = "Second";
    char result[128];
    myStrcat(strA, strB, result);
    std::cout << "Resulting string: " << result << std::endl;
    std::cout << "Expected:         FirstSecond" << std::endl;
}