#include <iostream>

using namespace std;

int bit_multiply(int a, int b) {
    if (a < b) {
        int temp = b;
        b = a;
        a = temp;
    }

    int b_binary_digits = 0;
    int b_temp = b;
    while (b_temp > 0) {
        b_binary_digits++;
        b_temp = b_temp>>1;
    }

    int product = 0;
    int b_subtract = 0;
    for (int i=b_binary_digits-1; i>0; i--) {
        if (b>>i) {
            product += a<<i;
            b -= 1<<i;
        }
    }

    return product;
}

int main() {
    int a = 3857;
    int b = 19920;
    cout << a << " * " << b << " = " << bit_multiply(a, b) << endl;
}
