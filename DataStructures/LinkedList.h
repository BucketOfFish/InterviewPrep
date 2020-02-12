#include <iostream>
#include <vector>
using namespace std;

class LinkedList {
private:
    class LinkedListNode {
    public:
        LinkedListNode *next = nullptr;
        int value = 0;
        LinkedListNode(int new_value);
        void set_next(LinkedListNode *new_node);
        void remove_next();
    };
    LinkedList::LinkedListNode *head = nullptr;
public:
    LinkedList();
    void append(int value);
    void remove();
    void print();
    bool is_empty();
};

