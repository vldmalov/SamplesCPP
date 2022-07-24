#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <numeric>
#include <functional>

template<typename T>
T sum_func(const T& a, const T& b) {
    return a + b;
}

template<typename T>
class mult {
public:
    int operator()(const T& a, const T& b) const {
        return a * b;
    }
};

int main(int argc, const char * argv[]) {
    
    std::list<int> ls = {5, 4, 3, 2, 1};
    int sum = std::accumulate(ls.begin(), ls.end(), 0);
    std::cout << "sum = " << sum << std::endl;
    
    int sum2 = std::accumulate(ls.begin(), ls.end(), 0, &sum_func<int>);
    std::cout << "sum = " << sum2 << std::endl;
    
    int multiplication = std::accumulate(ls.begin(), ls.end(), 1, mult<int>());
    std::cout << "mult = " << multiplication << std::endl;
    
    int multiplication2 = std::accumulate(ls.begin(), ls.end(), 1, std::multiplies<int>());
    std::cout << "mult 2 = " << multiplication2 << std::endl;
    
    //////////////// reverse sum
    std::cout.precision(12);
    
    float SMALL = 1.0 / (1 << 26);
    float f_array[5] = {1.0, 3*SMALL, 2*SMALL, SMALL, SMALL};
    
    float f_sum_1 = std::accumulate(&f_array[0], &f_array[5], 0.0f);
    std::cout << "f_sum_1 = " << f_sum_1 << std::endl;
    
    std::vector<float> f_vect(&f_array[0], &f_array[5]);
    float f_sum_2 = std::accumulate(f_vect.begin(), f_vect.end(), 0.0f);
    std::cout << "f_sum_2 = " << f_sum_2 << std::endl;
    
    float f_sum_3 = std::accumulate(f_vect.rbegin(), f_vect.rend(), 0.0f);
    std::cout << "f_sum_3 = " << f_sum_3 << std::endl;
    
    return 0;
}
