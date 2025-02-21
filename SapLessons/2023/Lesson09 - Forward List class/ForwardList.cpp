#include "ForwardList.h"

#include <iostream>

ForwardList::ForwardList()
: mHead(nullptr)
, mTail(nullptr)
{}

ForwardList::ForwardList(std::initializer_list<int> initList)
: ForwardList() {
    for(const int item : initList) {
        push_back(item);
    }
}

ForwardList::~ForwardList() {
    Node* currentNode = mHead;
    while(currentNode) {
        currentNode->data = 0;
        Node* node_for_remove = currentNode;
        currentNode = currentNode->next;
        delete node_for_remove;
    }
}

const Node* ForwardList::begin() const {
    return mHead;
}

const Node* ForwardList::end() const {
    return mTail;
}

int ForwardList::front() const {
    return mHead->data;
}

int ForwardList::back() const {
    return mTail->data;
}

Node* ForwardList::push_back(int val) {
    Node* newNode = new Node();
    newNode->next = nullptr;
    newNode->data = val;

    if(!mHead) {
        mHead = mTail = newNode;
    }
    else {
        mTail->next = newNode;
        mTail = newNode;
    }

    return mTail;
}

void ForwardList::revert() {
    if(!mHead) {
        return;
    }

    Node* prev = nullptr;
    Node* current = mHead;
    Node* next = nullptr;

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    std::swap(mHead, mTail);
}

std::ostream& operator<<(std::ostream& os, const ForwardList& ls)
{
    const Node* currentNode = ls.begin();
    while(currentNode) {
        os << currentNode->data << ", ";
        currentNode = currentNode->next;
    }
    
    return os;
}