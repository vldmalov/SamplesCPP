#include <iostream>

int main() {

    int array[40] = {1,2,3,4,5,67,8,9};
    std::replace(&array[0], &array[40], 1, 11);
    
    std::cout << "Array after replace" << std::endl;
    for(int item : array) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    std::string str("I live in Moscow");
    std::replace(str.begin(), str.end(), 'i', 'I');
    std::cout << "str = " << str << std::endl;
    
    std::string::iterator found = std::find(str.begin(), str.end(), 'M');
    std::reverse(found, str.end());
    std::cout << "str = " << str << std::endl;
}