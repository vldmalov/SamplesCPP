#include <iostream>
#include "ForwardList.h"

int main() {
    ForwardList list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);

    std::cout << "Source list: " << list << std::endl;
    list.Revert();
    std::cout << "List after revert operation: " << list << std::endl;
}