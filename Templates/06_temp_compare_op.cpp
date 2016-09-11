
#include <iostream>

template<typename T1, typename T2>
struct pair {
    
    T1 first;
    T2 second;
    
    pair()
    : first(T1())
    , second(T2())
    {}
    
    pair(const T1& x, const T2& y)
    : first(x)
    , second(y)
    {
    }
};

bool operator>(const pair<std::string, int>& lh, const pair<std::string, int>& rh) {
    
    if(lh.first != rh.first) {
        return lh.first > rh.first;
    }
    
    return lh.second > rh.second;
}

template<typename T>
const T& myMax(const T& first, const T& second)
{
    return (first > second) ? first : second;
}

int main(int argc, const char * argv[]) {
    
    pair<std::string, int> namePair("Alex", 32);
    namePair.first = "Michel";
    
    pair<std::string, int> namePair2("Vladimir", 23);
    
    int max_int_val = myMax(12, 47);
    std::cout << "max val is : " << max_int_val << std::endl;
    
    double max_double_val = myMax(-0.1234, -0.12345);
    std::cout << "max val is : " << max_double_val << std::endl;
    
    pair<std::string, int> maxNamePair = myMax(namePair, namePair2);
    std::cout << "Max name pair is " << maxNamePair.first << " " << maxNamePair.second << std::endl;
    
    return 0;
}
