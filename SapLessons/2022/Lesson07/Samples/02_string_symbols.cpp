#include <string>
#include <map>
#include <iostream>

int main()
{
  std::string famousQuote = "Life did not intend to make us perfect. Whoever is perfect belongs in a museum. -- Erich Maria Remarque";

  std::map<char, int> symbCounter;
  for(char& ch : famousQuote) {
    if(std::isalpha(ch)) {
      ++symbCounter[std::tolower(ch)];
    }
  }

  for(auto& symbData : symbCounter) {
    std::cout << symbData.first << " : " << symbData.second << std::endl;
  }
}