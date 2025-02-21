#pragma once
#include <iostream>

struct Node {
    int data{ 0 };
    Node* next{ nullptr };
};

class ForwardList {

public:
    ForwardList() = default;
    ~ForwardList();

    const Node* Front() const;
    const Node* Back() const;
    Node* PushBack(int val);
    void Revert();

    friend std::ostream& operator<<(std::ostream& os, const ForwardList& list);

private:
    Node* mHead{ nullptr };
    Node* mLast{ nullptr };
};

std::ostream& operator<<(std::ostream& os, const ForwardList& list);