#include <string>
#include <iostream>
#include <sstream>
int main()
{
	std::string famousQuote = "Life did not intend to make us perfect. Whoever is perfect belongs in a museum. -- Erich Maria Remarque";

	for (int i = 0; i < famousQuote.size(); i++)
		{
			if (famousQuote[i] == '.'|| famousQuote[i] == '-')
			famousQuote[i] = ' ';
		}	
	//for (char& ch : famousQuote) {
	//	if (iscntrl(ch)!=0) {
	//		ch=' ';
	//	}
	//}

	std::istringstream is{ famousQuote, std::istringstream::in };
	std::string longestWord;
	std::string currentWord;
	
	while (is >> currentWord) {
		std::cout << currentWord << std::endl;
	}
	
}