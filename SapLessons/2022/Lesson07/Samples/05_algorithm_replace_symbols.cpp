#include <string>
#include <iostream>
#include <algorithm>

int main()
{
  std::string famousQuote = "Success is not final; failure is not fatal: It is the courage to continue that counts. -- Winston Churchill";

  std::cout << "Source string = " << famousQuote << std::endl;
  std::replace_if(famousQuote.begin(), famousQuote.end(), [](char& ch){
    return !std::isalpha(ch);
  }, ' ');
  std::cout << "Result string = " << famousQuote << std::endl;
}
