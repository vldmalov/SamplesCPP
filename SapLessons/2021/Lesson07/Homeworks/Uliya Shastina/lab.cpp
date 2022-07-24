#include <string>
#include <iostream>
#include <sstream>
#include <regex>

int main()
{
    std::string famousQuote = "Life did not intend to make us perfect. Whoever is perfect belongs in a museum. -- Erich Maria Remarque";
    std::istringstream is{ famousQuote, std::istringstream::in };

    std::regex re("^[AEIOUYaeiouy][A-Za-z]*");
    std::smatch match;


    std::string longestWord;
    std::string currentWord;

   while (is >> currentWord) {
        std::regex_search(currentWord, match, re);

        if (match[0].length() == 0 || match[0].length() % 2 != 0) {
            continue;
        }

        std::cout << match[0] << std::endl;
        if (match[0].length() > longestWord.size()) {
            longestWord = match[0];
        }
    }
    std::cout << "Longest word is \"" << longestWord << "\" which contains ";
    std::cout << longestWord.size() << " letters." << std::endl;
    
}