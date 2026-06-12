#include <iostream>

using namespace std;

class Node {
private:
    int val;
    Node* next;
public:
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
    int getVal() {
        return val;
    }
    Node* getNext() {
        return next;
    }
    void setNext(Node* next) {
        this->next = next;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void add(int x) {
        if (head == nullptr) {
            tail = new Node(x);
            head = tail;
        } else {
            tail->setNext(new Node(x));
            tail = tail->getNext();
            // Node* copyHead = head;
            // while (copyHead->getNext() != nullptr) {
            //     copyHead = copyHead -> getNext();
            // }
            // copyHead->setNext(new Node(x));
        }
    }
    bool remove(int x) {
        if (head == nullptr) {
            return false;
        }
        if (head -> getNext() == nullptr && head -> getVal() == x) {
            head = nullptr;
            return true;
        }

        Node *copyHead = head;
        while (copyHead->getNext() != nullptr) {
            if (copyHead->getNext() != nullptr && copyHead->getNext()->getVal() == x) {
                // cout << "found removed element!\n";
                Node* removed = copyHead->getNext();
                copyHead->setNext(copyHead->getNext()->getNext());
                delete removed;
                return true;
            }
            copyHead = copyHead -> getNext();
        }
        
        return false;
    }
    void print() {
        Node *copyHead = head;
        while (copyHead != nullptr) {
            cout << copyHead -> getVal() << " -> ";
            copyHead = copyHead -> getNext();
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll = LinkedList();
    ll.add(10);
    ll.add(20);
    ll.add(30);

    ll.print();

    ll.remove(20);
    ll.remove(30);
    ll.remove(10);

    ll.print();

    return 0;
}