#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <sstream>


template<typename T1>
T1 make(const std::string& input)
{
    return T1(input.begin(), input.end());
}

template<typename T1>
void printVector(const std::vector<T1>& inputVector)
{
    std::stringstream ss;
    for_each(inputVector.begin(), inputVector.end(), [&ss](T1 ch){
        ss << ch;
    });
    std::cout << ss.str() << "\n";
}

//int main(int argc, const char * argv[]) {
//    char inputString[] = "Hello new brave world!";
//    std::reverse(inputString, inputString + strlen(inputString));
//    assert(std::string(inputString) == "!dlrow evarb wen olleH");
//    
//    std::string inputString2 = "Hello new brave world!";
//    std::reverse(inputString2.begin(), inputString2.end());
//    assert(std::string(inputString) == inputString2);
//    
//    std::vector<char> input3 = make< std::vector<char> >("Hello new brave world!");
//    printVector<char>(input3);
//    
//    std::reverse(input3.begin(), input3.end());
//    printVector<char>(input3);
//    
//    std::cout << "END\n";
//    return 0;
//}

#include <map>
#include <string>

void printStatusByName(const std::map<std::string, bool>& inputMap, const std::string& name)
{
    std::map<std::string, bool>::const_iterator it_found = inputMap.find(name);
    if( it_found != inputMap.end()) {
        std::cout << name << " has status " << it_found->second << "\n";
    } else {
        std::cout << name << " is not found" << "\n";
    }
}

int main(int argc, const char * argv[]) {
    
    std::map<std::string, bool> checkMap;
    checkMap["Andrew"] = true;
    checkMap["Elis"] = true;
    checkMap["John"] = false;
    checkMap["Tanya"] = true;
    
    printStatusByName(checkMap, "Tanya");
    printStatusByName(checkMap, "Oleg");
    printStatusByName(checkMap, "John");
}
