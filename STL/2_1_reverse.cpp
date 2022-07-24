#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

template<typename CONT_T>
void outputContainer(const std::string& header, const CONT_T& container) {
    
    std::cout << header << "\n";
    for(const typename CONT_T::value_type& item : container) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<char> vec = {'a', 'b', 'c', 'd', 'e'};
    std::deque<char> deq = {'a', 'b', 'c', 'd', 'e'};
    
    outputContainer<std::vector<char> >("Source vector", vec);
    outputContainer<std::deque<char> >("Source deque", deq);
    
    std::reverse(vec.begin(), vec.end());
    std::reverse(deq.begin(), deq.end());
    
    outputContainer<std::vector<char> >("Reverse vector", vec);
    outputContainer<std::deque<char> >("Reverse deque", deq);
    return 0;
}
