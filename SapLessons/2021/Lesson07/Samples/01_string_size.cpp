#include <iostream>
#include <string>

int main()
{
  std::string emptyString;
  std::cout << "emptyString = " << emptyString << "; size = " << sizeof(emptyString) << std::endl;

  std::string filledString{"Some important information"};
  std::cout << "filledString = " << filledString << "; size = " << sizeof(filledString) << std::endl;
}