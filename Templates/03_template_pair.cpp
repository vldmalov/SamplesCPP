#include <iostream>
#include <vector>

template<typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;
    
    pair(const T1& _first, const T2& _second)
    : first(_first), second(_second) {}
};

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& output, const pair<T1, T2>& pair )
{
    output << pair.first << " " << pair.second;
    return output;
}

template<typename T1, typename T2>
bool operator<(const pair<T1, T2>& left, const pair<T1, T2>& right)
{
    if(left.first != right.first) {
        return left.first < right.first;
    }
    
    return left.second < right.second;
}

template<typename T1>
void printVector(const std::vector<T1>& outputVector)
{
    std::for_each(outputVector.begin(), outputVector.end(), [](const T1& item){
        std::cout << item << "\n";
    });
}

int main(int argc, const char * argv[]) {
    
    using procPair = pair<std::string, int>;
    
    std::vector<procPair> processors;
    processors.reserve(10);
    processors.emplace_back("4004", 1971);
    processors.emplace_back("8008", 1972);
    processors.emplace_back("8080", 1974);
    processors.emplace_back("8086", 1978);
    processors.emplace_back("286", 1982);
    processors.emplace_back("388", 1985);
    processors.emplace_back("486", 1989);
    processors.emplace_back("Pentium", 1993);
    processors.emplace_back("Pentium Pro", 1995);
    
    std::cout << "Processors before sorting:\n";
    printVector<procPair>(processors);
    
    std::sort(processors.begin(), processors.end());
    
    std::cout << "Processors after sorting:\n";
    printVector<procPair>(processors);
    
    return 0;
}
