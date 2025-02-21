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

void myStrcpy(const char* src, char* dst)
{
	unsigned int i = 0;
	while (*src) 
	{
		dst[i] = *src;
    i++;
    src++;
	}
	dst[i] = '\0';
}

void myStrcat(const char* str_start, const char* str_end, char* str_result)
{
	unsigned int i = 0;
	while (*str_start != '\0')
	{
		str_result[i] = str_start[0];
		++str_start;
		++i;
	}

	while (*str_end != '\0')
	{
		str_result[i] = str_end[0];
		++str_end;
		++i;
	}
	str_result[i] = '\0';
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


int main()
{
    char str[128] = "My string";

    std::cout << "String size = " << strlen(str) << std::endl;
    std::cout << "String size = " << myStrlen(str) << std::endl;

    char strDst[128];
    MyRevert(str, strDst);

    std::cout << "Source string  : " << str << std::endl;
    std::cout << "Source string size = " << strlen(str) << std::endl;

    std::cout << "Reverted string: " << strDst << std::endl;
    std::cout << "Reverted string size = " << strlen(strDst) << std::endl;

    // MyRevert(str);
    // std::cout << "Reverted string: " << str << std::endl;
    // std::cout << "String size = " << myStrlen(str) << std::endl;

    // char str2[128];
    // myStrcpy(str, str2);
    // std::cout << "Copied string: " << str2 << std::endl;
    // std::cout << "String size = " << myStrlen(str2) << std::endl;

    // char strA[128] = "First";
    // char strB[128] = "Second";
    // char result[128];
    // myStrcat(strA, strB, result);
    // std::cout << "Concatinated string: " << result << std::endl;
    // std::cout << "String size = " << myStrlen(result) << std::endl;
  
}

// void myRevert(char* str)
// {
//   int leftIdx = 0;
//   int rightIdx = myStrlen(str) - 1;

//   while(leftIdx < rightIdx) {
//     std::swap(str[leftIdx++], str[rightIdx--]);
//   }
// }

// void myStrcpy(const char* src, char* dst)
// {
// 	unsigned int i = 0;
// 	while (*src != '\0') 
// 	{
// 		dst[i++] = *src;
// 		++src;
// 	}
// 	dst[i] = '\0';
// }

// void myStrcat(const char* str_start, const char* str_end, char* str_result)
// {
// 	unsigned int i = 0;

// 	while (*str_start)
// 	{
// 		str_result[i] = *str_start;
// 		++str_start;
// 		++i;
// 	}
// 	while (*str_end)
// 	{
// 		str_result[i] = *str_end;
// 		++str_end;
// 		++i;
// 	}
// 	str_result[i] = '\0';
// }