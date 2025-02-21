#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main(int argc, const char * argv[]) {
    
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    int array[40] = {10,20,30,40,50,60,70,80,90};
    
    std::copy(begin(vec), end(vec), &array[5]);
    
    std::cout << "Array after copy" << std::endl;
    for(int item : array) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec_dst = {10,20,30,40,50,60,70,80,90};
    std::copy(begin(vec), end(vec), back_inserter(vec_dst));

    std::cout << "Destination vector after copy" << std::endl;
    for(int item : vec_dst) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
