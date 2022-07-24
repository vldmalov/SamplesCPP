#include <iostream>
#include <sstream>
#include <string>

const std::string inputString{ "The International Business Machines Corporation (IBM) is an American multinational information technology company headquartered in Armonk, New York, with operations in over 170 countries. The company began in 1911, founded in Endicott, New York, as the Computing-Tabulating-Recording Company (CTR) and was renamed International Business Machines in 1924. IBM is incorporated in New York. IBM produces and sells computer hardware, middleware and software, and provides hosting and consulting services in areas ranging from mainframe computers to nanotechnology. IBM is also a major research organization, holding the record for most U.S.patents generated by a business (as of 2019) for 26 consecutive years. Inventions by IBM include the automated teller machine (ATM), the floppy disk, the hard disk drive, the magnetic stripe card, the relational database, the SQL programming language, the UPC barcode, and dynamic random - access memory (DRAM). The IBM mainframe, exemplified by the System / 360, was the dominant computing platform during the 1960s and 1970s." };

int main()
{
	std::istringstream iss(inputString, std::istringstream::in);

	int count{ 0 };
	std::string word;
	while (iss >> word)
	{
		++count;
	}
	std::cout << "Text contains " << count << " words" << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}