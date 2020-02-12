#include "LinkedList.h"

//---------------------------
// LinkedList class functions
//---------------------------

void LinkedList::append(int value) {
    if (head == nullptr) {
        head = new LinkedListNode(value);
        tail = head;
    }
    else {
        LinkedListNode *last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }
        last_node->set_next(new LinkedListNode(value));
        last_node->next->set_previous(last_node);
        last_node = last_node->next;
        tail = last_node;
    }
    m_size++;
}

void LinkedList::remove_head() {
    if (head == nullptr) {
        cout << "WARNING: no values in linked list" << endl;
        return;
    }
    head = head->next;
    m_size--;
}

void LinkedList::remove_tail() {
    if (head == nullptr) {
        cout << "WARNING: no values in linked list" << endl;
        return;
    }
    if (head->next == nullptr) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        LinkedList::LinkedListNode *last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }
        last_node = last_node->previous;
        last_node->remove_next();
        tail = last_node;
    }
    m_size--;
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

    for (int value : my_values) {
        my_list.append(value);
        my_list.print();
    }
    while (!my_list.empty()) {
        my_list.remove_tail();
        my_list.print();
    }

    for (int value : my_values) {
        my_list.append(value);
    }
    while (!my_list.empty()) {
        my_list.remove_head();
        my_list.print();
    }

    for (int value : my_values) {
        my_list.append(value);
    }
    my_list.swap();
    my_list.print();

    cout << my_list.tail_value() << endl;

    return 0;
}
