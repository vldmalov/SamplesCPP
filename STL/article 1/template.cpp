#include <iostream>
#include <vector>

template<typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;
    
    pair(const T1& _first, const T2& _second)
    : first(_first)
    , second(_second) {}
    
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
    
    typedef pair<std::string, int> personAge;
    
    std::vector<personAge> perconAgeGuide;
    perconAgeGuide.push_back(personAge("Alex", 29));
    perconAgeGuide.push_back(personAge("Vlad", 22));
    perconAgeGuide.push_back(personAge("Mary", 25));
    perconAgeGuide.push_back(personAge("Robby", 41));
    perconAgeGuide.push_back(personAge("Elena", 17));
    perconAgeGuide.push_back(personAge("Fedor", 25));
    perconAgeGuide.push_back(personAge("Boris", 17));
    perconAgeGuide.push_back(personAge("Venera", 25));
    
    std::cout << "Persons before sorting by names and ages:\n";
    printVector<personAge>(perconAgeGuide);
    
    std::sort(perconAgeGuide.begin(), perconAgeGuide.end());
    
    std::cout << "Persons after sorting by names and ages:\n";
    printVector<personAge>(perconAgeGuide);
    
    return 0;
}
