#include <deque>
#include <algorithm>
#include <iostream>
#include <random>

template<typename ContainerType>
void printContainer(const std::string& header, const ContainerType& container) {

    std::cout << header << std::endl;
    for(auto item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    
    std::deque<char> my_deque = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    std::random_shuffle(begin(my_deque), end(my_deque));
    
    printContainer("Deque after random shuffle", my_deque);
    
    std::deque<char>::size_type container_size = my_deque.size();
    
    std::srand(static_cast<unsigned>(std::time(0)));
    int randome = std::rand() % (container_size - 2);
    
    std::vector<char> my_vec(begin(my_deque) + randome, end(my_deque) - 1);
    printContainer("My vector after initialization", my_vec);
    std::cout << "Vector size = " << my_vec.size() << std::endl;
    std::cout << "Vector capacity = " << my_vec.capacity() << std::endl;
    
    std::deque<char>::const_iterator found_it = std::search(begin(my_deque), end(my_deque), begin(my_vec), end(my_vec));
    
    if(found_it != end(my_deque)) {
        std::cout << "Substring is found!\n";
        for(std::deque<char>::const_iterator it = found_it; it != end(my_deque); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Substring did not find";
    }
    
    return 0;
}
