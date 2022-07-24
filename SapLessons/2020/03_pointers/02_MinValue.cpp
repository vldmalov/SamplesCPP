#include <iostream>

int* GetMinItem(int* beginPtr, int* endPtr)
{
    if(beginPtr > endPtr) {
        return nullptr;
    }
    
    int* currentPtr = beginPtr;
    int* minPtr = beginPtr;
    
    while(currentPtr++ != endPtr)
    {
        if(*currentPtr < *minPtr)
        {
            minPtr = currentPtr;
        }
    }
    
    return minPtr;
}

int main()
{
    const size_t N = 8;
    int array[N] = { 10, -20, 30, 40, 50, -60, 0, -30 };

    int* minPtr = GetMinItem(array, array + N);
    
    std::cout << "Min value is " << *minPtr << "\n";
    std::cout << "Position in array is " << minPtr - array << "\n";
     
    return 0;
}
