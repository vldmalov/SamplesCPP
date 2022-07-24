#include <iostream>
#include <list>

typedef std::list<std::string> StrList;

class FirstSymbolComparator {
public:
    explicit FirstSymbolComparator(char a)
    : m_firstSymbol(a){}
    
    bool operator()(const std::string& input) const {
        
        if(input.empty()) {
            return false;
        }
        
        return input[0] == m_firstSymbol;
    }
    
private:
    char m_firstSymbol;
};

int main()
{
    StrList ls {"Anna", "Boris", "Mary", "Vladimir", "Artyom", "Elis", "Yakov"};
    
    StrList::iterator found = std::find_if(ls.begin(), ls.end(), FirstSymbolComparator('A'));
    while(found != ls.end()) {
        std::cout << "Next found item is " << *found << std::endl;
        found = std::find_if(++found, ls.end(), FirstSymbolComparator('A'));
    }
}