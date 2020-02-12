#include "LinkedList.h"

//---------------------------
// LinkedList class functions
//---------------------------

LinkedList::LinkedList () {
    head = nullptr;
}

void LinkedList::append(int value) {
    if (head == nullptr) {
        head = new LinkedListNode(value);
    }
    else {
        LinkedListNode *last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }
        last_node->set_next(new LinkedListNode(value));
    }
}

void LinkedList::remove() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        head = nullptr;
        return;
    }
    else {
        LinkedList::LinkedListNode *second_to_last_node = nullptr;
        LinkedList::LinkedListNode *last_node = head;
        while (last_node->next != nullptr) {
            second_to_last_node = last_node;
            last_node = last_node->next;
        }
        second_to_last_node->remove_next();
    }
}

void LinkedList::print() {
    LinkedList::LinkedListNode *this_node = head;
    while (this_node != nullptr) {
        cout << this_node->value;
        this_node = this_node->next;
        if (this_node != nullptr) cout << ", ";
    }
    cout << endl;
}

bool LinkedList::is_empty() {
    return head == nullptr;
}

//-------------------------------
// LinkedListNode class functions
//-------------------------------

LinkedList::LinkedListNode::LinkedListNode(int new_value) {
    value = new_value;
}

void LinkedList::LinkedListNode::set_next(LinkedListNode *new_node) {
    next = new_node;
}

void LinkedList::LinkedListNode::remove_next() {
    next = nullptr;
}

//-----
// Main
//-----

int main() {
    LinkedList my_list;
    vector<int> my_values {3, 5, 2, 6, 7, 5};
    for (int value : my_values) {
        my_list.append(value);
        my_list.print();
    }
    while (!my_list.is_empty()) {
        my_list.remove();
        my_list.print();
    }
    return 0;
}
