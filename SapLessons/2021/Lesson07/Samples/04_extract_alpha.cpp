#include <string>
#include <iostream>

int main()
{
  std::string famousQuote = "Success is not final; failure is not fatal: It is the courage to continue that counts. -- Winston Churchill";

  std::cout << "Source string = " << famousQuote << std::endl;
  for (char& ch : famousQuote) {
    if (!std::isalpha(ch)) {
      ch=' ';
    }
  }
  std::cout << "Result string = " << famousQuote << std::endl;
}
