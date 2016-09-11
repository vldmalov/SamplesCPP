#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template<typename ContainerType>
void print_container(const std::string& header, const ContainerType& input_container) {

    std::cout << header << std::endl;
    for(const typename ContainerType::value_type& item_val : input_container) {
        std::cout << item_val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {

    // back_insert_iterator<C> - push_back
    // front_insert_iterator<C> - push_front
    // insert_iterator<C> - insert
    
    std::vector<int> vec = {1,34,345,-23,0,17};
    std::deque<int> deq1(4, -12);
    std::deque<int> deq2(4, -12);
    std::list<int> ls;
    
    //std::copy(begin(vec), end(vec), deq.begin());
    
    //std::copy(begin(vec), end(vec), std::back_insert_iterator< std::deque<int>>(deq1));
    std::copy(begin(vec), end(vec), std::back_inserter(deq1));
    
    print_container<std::deque<int> >("Deque items 1", deq1);
    
//    std::copy(begin(vec), end(vec), std::front_insert_iterator< std::deque<int>>(deq2));
    std::copy(begin(vec), end(vec), std::front_inserter(deq2));
    print_container<std::deque<int> >("Deque items 2", deq2);
    
    std::copy(vec.begin(), vec.end(), std::inserter(ls, ls.begin()));
    print_container<std::list<int> >("List items", ls);
    
    //
    std::vector<std::string> s_vec = {"a first", "c second", "e word"};
    std::list<std::string> s_ls = {"abc", "bcd", "def"};
    
    std::deque<std::string> dq_merged = {"AA", "ZZ", "YY", "BB"};
    
    std::merge(s_vec.begin(), s_vec.end(), s_ls.begin(), s_ls.end(), std::inserter(dq_merged, dq_merged.begin() + 2 ));
    print_container<std::deque<std::string> >("Merged deque", dq_merged);
    
    return 0;
}
