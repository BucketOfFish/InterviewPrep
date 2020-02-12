#include <iostream>
#include <vector>

using namespace std;

int find_magic_index(vector<int> *array, int begin_index, int end_index) {
    // Return a magic index (only need one)
    if (begin_index > end_index)
        return -1;
    int index = (begin_index + end_index)/2;
    int value = array->at(index);
    if (index == value)
        return index;
    else if (index > value) {
        int return_index = find_magic_index(array, begin_index, value);
        if (return_index > -1) return return_index;
        return_index = find_magic_index(array, index+1, end_index);
        if (return_index > -1) return return_index;
    }
    else {
        int return_index = find_magic_index(array, value, end_index);
        if (return_index > -1) return return_index;
        return_index = find_magic_index(array, begin_index, index-1);
        if (return_index > -1) return return_index;
    }
    return -1;
}

int main() {
    int magic_index = 7855;
    int array_size = 10000;

    vector<int> array;
    int last_value = -50;
    array.push_back(last_value);
    for (int i=1; i<magic_index; i++) {
        last_value += rand() % (i-last_value-1);
        array.push_back(last_value);
    }
    array.push_back(magic_index);
    last_value = magic_index;
    for (int i=magic_index+1; i<array_size; i++) {
        last_value += (rand()%3) + max(i-last_value+1, 0);
        array.push_back(last_value);
    }

    cout << "The magic index is " << find_magic_index(&array, 0, array.size()-1) << endl;
}
