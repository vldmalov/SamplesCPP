#include <iostream>
#include <array>
#include <numeric>

template<typename CONT_T>
int find_unique(const CONT_T& input_array)
{
    int result(0);
    for(auto it = input_array.begin(), it_end = input_array.end(); it != it_end; ++it)
    {
        result ^= *it;
    }

    return result;
}

int xor_add(int val1, int val2)
{
    return val1 ^ val2;
}

template<typename CONT_T>
int find_unique2(const CONT_T& input_array)
{
    int result = std::accumulate(input_array.begin(), input_array.end(), 0, xor_add);
    return result;
}

int main()
{
    std::array<int, 7> arr = {12, -4, 3, -4, -5, 12, 3};
    std::cout << "unique value is " << find_unique(arr) << std::endl;
    std::cout << "unique value is " << find_unique2(arr) << std::endl;
}