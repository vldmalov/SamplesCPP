#include "iostream"
#include "vector"
#include "assert.h"


template<typename T>
class stack {

public:
    stack() {};
    ~stack() {};

    void push(const T& item) {
        m_container.push_back(item);
    }

    T pop(void) {
        if(m_container.empty()) {
            throw std::out_of_range("stack::pop out of range");
        }
        T result = m_container.back();
        m_container.pop_back();

        return result;
    }

    const T& top() const {
        if(m_container.empty()) {
            throw std::out_of_range("stack::pop out of range");
        }
        return m_container.back();
    }

    size_t size() const {
        return m_container.size();
    }

private:
    std::vector<T> m_container;
};

typedef stack<int> int_stack;
typedef stack<std::string> str_stack;


int main() 
{
    {
        int_stack st;
        st.push(12);  st.push(-7); st.push(12); st.push(5);
        assert(st.size() == 4);  
        assert(st.top() == 5);
        assert(st.top() == 5);
        
        int result = st.pop(); 
        assert(result == 5);
        assert(st.top() == 12);
        assert(st.size() == 3); 
    }

    {
        str_stack st2;
        assert(st2.size() == 0);
        st2.push("Andrew");
        st2.push("Irina");
        st2.push("Anjella");
        assert(st2.size() == 3);
        st2.pop(); st2.pop();
        std::string result = st2.pop();
        assert(result == "Andrew");
    }


    return 0;
}