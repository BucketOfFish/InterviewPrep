#include "Stack.h"

int Stack::top() {
    return stack.tail_value();
}

bool Stack::empty() {
    return stack.empty();
}

int Stack::size() {
    return stack.size();
}

void Stack::push(int new_value) {
    stack.append_tail(new_value);
}

int Stack::pop() {
    if (Stack::size() == 0) {
        cout << "WARNING: no values in stack" << endl;
        return -1;
    }
    int return_value = stack.tail_value();
    stack.remove_tail();
    return return_value;
}

void Stack::swap() {
    stack.swap();
}

void Stack::print() {
    stack.print();
}

//-----
// Test
//-----

int test() {
    Stack my_stack;
    vector<int> my_values {8, 12, 2, -4, 0, 2};

    for (int value : my_values) {
        my_stack.push(value);
        my_stack.print();
    }
    while (!my_stack.empty()) {
        my_stack.pop();
        my_stack.print();
    }

    for (int value : my_values) {
        my_stack.push(value);
    }
    my_stack.swap();
    my_stack.print();

    cout << my_stack.top() << endl;

    cout << my_stack.size() << endl;

    return 0;
}
