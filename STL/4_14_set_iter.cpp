#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

template<typename ContainerType>
void printContainer(const std::string& header, const ContainerType& container) {

    std::cout << header << "\n";
    for(const typename ContainerType::value_type& item : container) {
        
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template<typename KeyType, typename ValueType>
void printMap(const std::string& header, const std::map<KeyType, ValueType>& container) {

    std::cout << header << std::endl;
    
    for(const std::pair<KeyType, ValueType>& item : container) {
        std::cout << "key = " << item.first << " value = " << item.second << std::endl;
    }
}

template<typename ContainerType>
bool erase_item(ContainerType& container, const typename ContainerType::value_type& key)
{
    typename ContainerType::const_iterator found_it = container.find(key);
    if(found_it != end(container)) {
        std::cout << "item key " << key << " is found!\n";
        container.erase(found_it);
        return true;
    } else {
        std::cout << "item key " << key << " did not find!\n";
    }
    
    return false;
}

int main(int argc, const char * argv[]) {

//    std::set<int> my_set = {34, 45, 22, 12, -3, 2};
//    my_set.insert(32);
//    
//    printContainer("My set container after initialization: ", my_set);
//    
//    erase_item(my_set, 12);
//    printContainer("My set container after try to erase item with key 12: ", my_set);
//    
//    erase_item(my_set, -7);
//    printContainer("My set container after try to erase item with key -7: ", my_set);
//    
//    std::vector<int> vec(12, 3);
//    vec.push_back(43);
//    vec.push_back(12);
//    
//    int seed = std::chrono::system_clock::now().time_since_epoch().count();
//    std::shuffle(begin(vec), end(vec), std::default_random_engine(seed));
//    printContainer("My vector after initialization", vec);
//    
//    std::vector<int> vec2(my_set.begin(), --my_set.end());
//    printContainer("My vector 2 after initialization", vec2);
    
//    erase_item(vec2, 22);
//    printContainer("My vector 2 after erase 22", vec2);
//    
//    erase_item(vec2, -22);
//    printContainer("My vector 2 after erase 22", vec2);
    
    std::map<std::string, int> my_map;
    my_map.insert(std::pair<std::string, int>("BTF", -7));
    my_map.insert(std::pair<std::string, int>("ASD", 12));
    my_map.insert(std::make_pair("FFF", 14));
    my_map["EEe"] = 100;
    
    printMap("My map container after initialization", my_map);
    
    auto found_it = my_map.find("ASD");
    if(found_it != my_map.end()) {
        my_map.erase(found_it);
    }
    
    printMap("My map container after erase ASD", my_map);
    
    return 0;
}
