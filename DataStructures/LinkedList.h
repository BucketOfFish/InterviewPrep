#include <iostream>
#include <vector>
using namespace std;

class LinkedList {
private:
    class LinkedListNode {
    public:
        LinkedListNode *next = nullptr;
        LinkedListNode *previous = nullptr;
        int value = 0;
        LinkedListNode(int new_value);
        void set_next(LinkedListNode *new_node);
        void set_previous(LinkedListNode *previous_node);
        void remove_next();
    };
    LinkedList::LinkedListNode *head = nullptr;
    LinkedList::LinkedListNode *tail = nullptr;
public:
    void append(int value);
    void remove();
    void print();
    bool is_empty();
    void swap();
};
