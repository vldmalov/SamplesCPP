#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {

    std::vector<int> vec = {23, -5, 0, 54, -2, 1, 22, -5, 102, 2, 41,93};
    std::sort(begin(vec), end(vec));
    
    const int FIND_VAL = -5;
    bool found = std::binary_search(begin(vec), end(vec), FIND_VAL);
    std::cout << (found ? "true" : "false") << std::endl;
    std::cout << FIND_VAL << " is " << (found ? "found" : "not found") << std::endl;
    return 0;
}
