#include <iostream>
#include <vector>
#include <cassert>


class IntWrapper {
public:
    IntWrapper()
    : m_value(0)
    { std::cout << "IntWrapper constructor\n"; }

    ~IntWrapper() { std::cout << "IntWrapper destructor\n"; }

private:
    int m_value;
};

typedef std::shared_ptr<IntWrapper> SharedIntWrapper;

void Func(SharedIntWrapper pVal, unsigned currentCount)
{
    assert(pVal.use_count() == currentCount + 1);
}

int main()
{
    //SharedIntWrapper pWrappedVal(new IntWrapper());
    SharedIntWrapper pWrappedVal = std::make_shared<IntWrapper>();
    assert(pWrappedVal.use_count() == 1);
    
    {
        std::vector<SharedIntWrapper> v;
        v.push_back(pWrappedVal);
        v.push_back(pWrappedVal);
        assert(pWrappedVal.use_count() == 3);
        v.pop_back();
        assert(pWrappedVal.use_count() == 2);
        Func(v.front(), 2);
        Func(v.front(), 2);

        SharedIntWrapper pWrappedVal2 = pWrappedVal;
        assert(pWrappedVal.use_count() == 3);
        pWrappedVal2 = nullptr;
        assert(pWrappedVal.use_count() == 2);
        pWrappedVal2 = nullptr;
        assert(pWrappedVal.use_count() == 2);
    }

    assert(pWrappedVal.use_count() == 1);
    assert(pWrappedVal.unique() == true);
}