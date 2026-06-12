#include <iostream>

using namespace std;

class Node {
private:
    int val;
    Node* next;
    Node* prev;
public:
    Node(int val) {
        this->val = val;
    }
    Node* getNext() {
        return this->next;
    }
    Node* getPrev() {
        return this->prev;
    }
    int getVal() {
        return this->val;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() {
        head = tail = nullptr;
    }

    void add(int x) {
        // TODO: implement the add method;
    }
}

int main() {
    return 0;
}