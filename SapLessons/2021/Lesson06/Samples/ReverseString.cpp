#include <iostream>
#include <string>

void reverseString(std::string& s)
{
    size_t leftIdx{0};
    size_t rightIdx {s.size() - 1};
    
    while(leftIdx < rightIdx)
    {
        std::swap(s[leftIdx++], s[rightIdx--]);
    }
}

int main(int argc, char* argv[])
{
	std::string lyrics("Nothing Else Matters");
	reverseString(lyrics);

	std::cout << "Reversed string: " << lyrics << std::endl;
}