#include <iostream>
#include "ForwardList.h"

int main() {
    ForwardList list{1, 2, 3, 4, 5};
    list.push_back(7);
    list.push_back(8);

    std::cout << "Source list: " << list << std::endl;

    list.revert();

    std::cout << "Reverted list: " << list << std::endl;

//    for(const Node& item : list) {
//        std::cout << "Item " << item.data;
//        if(!item.next) {
//            std::cout << " is the last one";
//        }
//        std::cout << std::endl;
//    }

    return 0;
}