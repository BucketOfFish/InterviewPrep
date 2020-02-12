#include "Queue.h"

bool Queue::empty() {
    return queue.empty();
}

int Queue::size() {
    return queue.size();
}

void Queue::push_back(int new_value) {
    queue.append_tail(new_value);
}

int Queue::pop_back() {
    return queue.remove_tail();
}

void Queue::push_front(int new_value) {
    return queue.append_head(new_value);
}

int Queue::pop_front() {
    return queue.remove_head();
}

void Queue::swap() {
    queue.swap();
}

void Queue::print() {
    queue.print();
}

//-----
// Test
//-----

int test() {
    Queue my_queue;
    vector<int> my_values {8, 12, 2, -4, 0, 2};

    // check push_back and pop_back
    for (int value : my_values) {
        my_queue.push_back(value);
        my_queue.print();
    }
    while (!my_queue.empty()) {
        my_queue.pop_back();
        my_queue.print();
    }

    // check push_front and pop_front
    for (int value : my_values) {
        my_queue.push_front(value);
        my_queue.print();
    }
    while (!my_queue.empty()) {
        my_queue.pop_front();
        my_queue.print();
    }

    // check swap
    for (int value : my_values) {
        my_queue.push_back(value);
    }
    my_queue.swap();
    my_queue.print();

    return 0;
}
