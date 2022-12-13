#include <stdio.h>
#include <string.h>
#include <iostream>

int main ()
{
  char str1[128]="Plain C String";
  char str2[128];

  strcpy(str2, str1);
  strcpy(str1, "Another plain string");
  
  std::cout << "str1 = " << str1 << "\n";
  std::cout << "str2 = " << str2 << "\n";
  return 0;
}