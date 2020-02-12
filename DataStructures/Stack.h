#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

class Stack {
private:
    LinkedList stack;
public:
    int top();
    bool empty();
    int size();
    void push(int new_value);
    int pop();
    void swap();
    void print();
};
