// One direction linked list
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class list {

public:
    list()
    : m_head(nullptr)
    , m_last(nullptr)
    {}
    
    ~list()
    {
        Node* current_node = m_head;
        while(current_node) {
            current_node->data = 0;
            Node* node_for_remove = current_node;
            current_node = current_node->next;
            delete node_for_remove;
        }
    }
    
    const Node* front() const
    {
        return m_head;
    }
    
    const Node* back() const
    {
        return m_last;
    }
    
    Node* push_back(int val) {
        Node* new_node = new Node();
        new_node->next = nullptr;
        new_node->data = val;
        
        if(!m_head) {
            m_head = m_last = new_node;
        }
        else {
            m_last->next = new_node;
            m_last = new_node;
        }
        
        return m_last;
    }
    
    void revert() {
        if(!m_head) {
            return;
        }
        
        Node* prev = nullptr;
        Node* current = m_head;
        Node* next = nullptr;
        
        while(current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        std::swap(m_head, m_last);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const list& ls);
    
private:
    Node* m_head;
    Node* m_last;
};

std::ostream& operator<<(std::ostream& os, const list& ls)
{
    const Node* current_node = ls.front();
    while(current_node) {
        os << current_node->data << ", ";
        current_node = current_node->next;
    }
    
    return os;
}

int main() {
    
    {
        list myList;
        myList.push_back(1);
        myList.push_back(2);
        myList.push_back(3);
        myList.push_back(4);
        
        std::cout << "My list: " << myList << std::endl;
        
        myList.revert();
        
        std::cout << "My list after revert: " << myList << std::endl;
    }

    return 0;
}