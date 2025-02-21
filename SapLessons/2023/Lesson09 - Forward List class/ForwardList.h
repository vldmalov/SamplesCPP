#pragma once

#include "ForwardList.h"

#include <iosfwd>
#include <initializer_list>

struct Node {
    int data;
    Node* next;
};

class ForwardList {
public:
    ForwardList();
    ForwardList(std::initializer_list<int>);
    ~ForwardList();

    const Node* begin() const;
    const Node* end() const;

    int front() const;
    int back() const;

    Node* push_back(int val);
    void revert();

    friend std::ostream& operator<<(std::ostream& os, const ForwardList& ls);

private:
    Node* mHead;
    Node* mTail;
};

std::ostream& operator<<(std::ostream& os, const ForwardList& ls);
