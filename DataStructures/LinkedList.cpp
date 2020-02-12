#include "LinkedList.h"

//---------------------------
// LinkedList class functions
//---------------------------

void LinkedList::append_head(int value) {
    if (head == nullptr) {
        head = new LinkedListNode(value);
        tail = head;
    }
    else {
        head->set_previous(new LinkedListNode(value));
        head->previous->set_next(head);
        head = head->previous;
    }
    m_size++;
}

void LinkedList::append_tail(int value) {
    if (head == nullptr) {
        head = new LinkedListNode(value);
        tail = head;
    }
    else {
        tail->set_next(new LinkedListNode(value));
        tail->next->set_previous(tail);
        tail = tail->next;
    }
    m_size++;
}

int LinkedList::remove_head() {
    if (head == nullptr) {
        cout << "WARNING: no values in linked list" << endl;
        return -1;
    }
    int return_value = head->value;
    head = head->next;
    m_size--;
    return return_value;
}

int LinkedList::remove_tail() {
    if (head == nullptr) {
        cout << "WARNING: no values in linked list" << endl;
        return -1;
    }
    int return_value = tail->value;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        tail->previous->remove_next();
        tail = tail->previous;
    }
    m_size--;
    return return_value;
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

bool LinkedList::empty() {
    return head == nullptr;
}

void LinkedList::swap() {
    LinkedListNode *last_node = tail;
    while (last_node->previous != nullptr) {
        LinkedListNode *temp_node = last_node->next;
        last_node->next = last_node->previous;
        last_node->previous = temp_node;
        last_node = last_node->next;
    }
    head = tail;
    tail = last_node;
    tail->next = nullptr;
}

int LinkedList::size() {
    return m_size;
}

int LinkedList::head_value() {
    return head->value;
}

int LinkedList::tail_value() {
    return tail->value;
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

void LinkedList::LinkedListNode::set_previous(LinkedListNode *previous_node) {
    previous = previous_node;
}

void LinkedList::LinkedListNode::remove_next() {
    next = nullptr;
}

//-----
// Test
//-----

int test() {
    LinkedList my_list;
    vector<int> my_values {3, 5, 2, 6, 7, 5};

    // check append_tail and remove_tail
    for (int value : my_values) {
        my_list.append_tail(value);
        my_list.print();
    }
    while (!my_list.empty()) {
        my_list.remove_tail();
        my_list.print();
    }

    // check append_head and remove_head
    for (int value : my_values) {
        my_list.append_head(value);
        my_list.print();
    }
    while (!my_list.empty()) {
        my_list.remove_head();
        my_list.print();
    }

    // check swap
    for (int value : my_values) {
        my_list.append_tail(value);
    }
    my_list.swap();
    my_list.print();

    // check peeks
    cout << my_list.head_value() << endl;
    cout << my_list.tail_value() << endl;

    return 0;
}
