#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

template<typename ContainerType>
void printContainer(const std::string& header, const ContainerType& container) {
    
    std::cout << header << std::endl;
    for(auto item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

class FindPredict {

public:
    
    FindPredict(size_t min, size_t max)
    : m_min_value(min)
    , m_max_value(max)
    {}
    
    bool operator()(size_t val) const {
        
        return ( val >= m_min_value && val <= m_max_value);
    }
    
private:
    size_t m_max_value;
    size_t m_min_value;
};


int main(int argc, const char * argv[]) {

    const size_t ITEM_COUNT = 20;
    std::vector<size_t> my_vec;
    
    for(size_t i = 0; i < ITEM_COUNT; ++i) {
        
        my_vec.push_back(2*i);
    }
    
    printContainer("Vector after filling", my_vec);
    
    std::random_shuffle(begin(my_vec), end(my_vec));
    printContainer("Vector after shuffle", my_vec);
    
    std::list<size_t> my_list;
    
    
    std::copy(std::begin(my_vec), std::end(my_vec), std::front_inserter(my_list));
    
    printContainer("List after copyed items from vector", my_list);
    
    std::list<size_t>::const_iterator found_it = std::find_if(begin(my_list), end(my_list), FindPredict(24, 26));
    std::cout << "Found value is " << *found_it << " and next value " << *(++found_it);
    
   // auto found_it = std::found_if(my_list.rbegin(), my_list.rend(), FindPredict(24,26));
    return 0;
}
