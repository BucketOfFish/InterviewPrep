#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

class Queue {
private:
    LinkedList queue;
public:
    bool empty();
    int size();
    void push_back(int new_value);
    int pop_back();
    void push_front(int new_value);
    int pop_front();
    void swap();
    void print();
};
