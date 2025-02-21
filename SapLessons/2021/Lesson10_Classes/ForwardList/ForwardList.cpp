#include "ForwardList.h"

ForwardList::~ForwardList() {
    Node* node = mHead;
    while(node) {
        node->data = 0;
        Node* nodeForRemove = node;
        node = node->next;
        delete nodeForRemove;
    }
}

const Node* ForwardList::Front() const {
    return mHead;
}

const Node* ForwardList::Back() const {
    return mLast;
}

Node* ForwardList::PushBack(int val) {
    Node* newNode = new Node();
    newNode->next = nullptr;
    newNode->data = val;

    if(!mHead) {
        mHead = newNode;
    }
    else {
        mLast->next = newNode;
    }
    mLast = newNode;

    return mLast;
}

void ForwardList::Revert() {
    if(!mHead) {
        return;
    }

    Node* current = mHead;
    Node* prev = nullptr;
    Node* next = nullptr;

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    std::swap(mHead, mLast);
}

std::ostream& operator<<(std::ostream& os, const ForwardList& list) {
    const Node* node = list.Front();
    while(node) {
        os << node->data << ", ";
        node = node->next;
    }
    return os;
}