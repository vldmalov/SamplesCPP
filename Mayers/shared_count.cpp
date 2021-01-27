#include <iostream>
#include <vector>
#include <cassert>

class WrappedInt {
public:
    using Ptr = std::shared_ptr<WrappedInt>;

    explicit WrappedInt(int val) : _value(val) {
        std::cout << "WrappedInt has been constructed" << std::endl;
    }

    ~WrappedInt() {
        std::cout << "WrappedInt has been destructed" << std::endl;
    }

private:
    int _value{ 0 };
};

void Func(WrappedInt::Ptr pVal, unsigned count)
{
    assert(pVal.use_count() == count);
}

int main()
{
    //WrappedInt::Ptr pWrappedVal(new WrappedInt(5));
    WrappedInt::Ptr pVal = std::make_shared<WrappedInt>(5);
    assert(pVal.use_count() == 1);

    {
        std::vector<WrappedInt::Ptr> vec;
        vec.push_back(pVal); vec.push_back(pVal);
        assert(pVal.use_count() == 3);
        vec.pop_back();
        assert(pVal.use_count() == 2);
        Func(vec.front(), 3);
    }
    assert(pVal.use_count() == 1);

    WrappedInt::Ptr pVal2 = pVal;
    assert(pVal.use_count() == 2);
    pVal2 = nullptr;

    assert(pVal.use_count() == 1);
    assert(pVal.unique() == true);
}