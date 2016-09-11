#include "iostream"
#include "vector"
#include "list"

template<typename CONTAINER_TYPE>
void print_container(const CONTAINER_TYPE& container)
{
    std::cout << "print_container " << std::endl;
    typename CONTAINER_TYPE::const_iterator it;
    typename CONTAINER_TYPE::const_iterator it_end = container.end();
    for(it = container.begin(); it != it_end; ++it)
    {
        std::cout << "* " << *it << std::endl;
    }
}

int main() {

    std::list<int> iList;
    iList.push_back(13); iList.push_back(24); iList.push_back(-2); iList.push_back(109);

    print_container(iList);


    return 0;
}