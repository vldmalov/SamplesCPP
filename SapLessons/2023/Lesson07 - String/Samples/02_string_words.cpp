#include <string>
#include <iostream>
#include <sstream>

int main()
{
  std::string famousQuote = "Life did not intend to make us perfect. Whoever is perfect belongs in a museum. -- Erich Maria Remarque";
  std::istringstream is{famousQuote, std::istringstream::in };

  std::string longestWord;
  std::string currentWord;
  while(is >> currentWord) {
    std::cout << currentWord << std::endl;

    if(currentWord.size() > longestWord.size()) {
      longestWord = currentWord;
    }
  }

  std::cout << "Longest word is \"" << longestWord << "\" which contains ";
  std::cout << longestWord.size() << " letters." << std::endl;
}
