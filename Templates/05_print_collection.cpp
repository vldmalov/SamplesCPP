#include "iostream"
#include "vector"
#include "list"

template<typename CONT_T>
void print_container(const CONT_T& container)
{
    std::cout << "print_container " << std::endl;
    typename CONT_T::const_iterator it;
    typename CONT_T::const_iterator it_end = container.end();
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