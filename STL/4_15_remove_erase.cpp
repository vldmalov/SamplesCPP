#include <iostream>
#include <vector>
#include <algorithm>

template<typename CONT_T>
void printContainer(const CONT_T& container)
{
    for(const typename CONT_T::value_type& ch : container) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void printItem(const T& item)
{
    std::cout << item << " ";
}

int main()
{
    std::string name = "alexandra";
    std::vector<char> vec = std::vector<char>(name.begin(), name.end());
    printContainer(vec);

    std::vector<char>::const_iterator end_it = std::remove(vec.begin(), vec.end(), 'a');
    printContainer(vec);

    vec.erase(end_it, vec.end());
    std::for_each(vec.begin(), vec.end(), printItem<char>);
}