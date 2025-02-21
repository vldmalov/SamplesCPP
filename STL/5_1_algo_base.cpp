#include "algorithm"
#include <iostream>


void printArray(const std::string& header, int* array, size_t count) {

    std::cout << header << "\n";
    for(int idx = 0; idx < count; ++idx) {
        std::cout << array[idx] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {

    const int COUNT = 20;
    int array[COUNT];
    
    for(unsigned i = 0; i < COUNT; ++i) {
        array[i] = std::rand() % 99;
    }
    printArray("Array after initialization", array, COUNT);
    
    std::sort(&array[0], &array[COUNT]);
    printArray("Array after sort", array, COUNT);
    
    int array2[COUNT];
    
    std::reverse_copy(&array[0], &array[COUNT], &array2[0]);
    
    printArray("Reversed copy array", array2, COUNT);
    
    std::reverse(&array2[2], &array2[18]);
    
    printArray("Array 2 after partial reverse", array2, COUNT);
    
    std::random_shuffle(&array2[0], &array2[COUNT]);
    
    printArray("Array 2 after random shuffle", array2, COUNT);
    
    std::sort(&array2[0], &array2[COUNT], std::greater<int>());
    printArray("Array 2 after greater sort", array2, COUNT);

    return 0;
}
