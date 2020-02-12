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
    int m_size = 0;
public:
    void append_head(int value);
    void append_tail(int value);
    int remove_head();
    int remove_tail();
    void print();
    bool empty();
    void swap();
    int size();
    int head_value();
    int tail_value();
};
