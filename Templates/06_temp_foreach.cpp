#include <iostream>
#include <vector>

template<typename T>
class increase {
public:
    void operator()(T& val) {
        ++val;
    }
};

template<typename CONT_T>
void printContainer(const std::string& header, const CONT_T& container)
{
    std::cout << header << "\n";
    for(const typename CONT_T::value_type& ch : container) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
}

int main() {
    
    const std::string INPUT_STRING = "I live in Moscow";
    
    std::vector<char> char_container = std::vector<char>(INPUT_STRING.begin(), INPUT_STRING.end());
    printContainer< std::vector<char> >("char_container before increase: ", char_container);
    for_each(char_container.begin(), char_container.end(), increase<char>());
    printContainer< std::vector<char> >("char_container after increase: ", char_container);

    return 0;
}
