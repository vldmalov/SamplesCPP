#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include <iterator>

int main() {
    
    std::cout << "MERGE ALGORITHM \n";
    
    std::vector<int> input_vector = {32, 45, 12, 47, 23};
    std::sort(begin(input_vector), end(input_vector));
    
    for(int i : input_vector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::list<int> input_list = {-32, 3, -13, 31, 100};
    input_list.sort();
    
    std::deque<int> output_deque;
    std::merge(begin(input_vector), begin(input_vector)+2, begin(input_list), end(input_list), back_inserter(output_deque));
    
    for(int item : output_deque) {
        std::cout << item << " ";
    }

    return 0;
}