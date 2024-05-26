#include <iostream>
using namespace std;

template<class T>
class DoubleLinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;

        Node(const T& value);

        ~Node() {
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoubleLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(const T& value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void print_list() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

template<class T>
DoubleLinkedList<T>::Node::Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}

int main() {
    DoubleLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.prepend(0);
    list.print_list();

    return 0;
}
