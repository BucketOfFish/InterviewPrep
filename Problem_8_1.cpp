#include <iostream>
#include <unordered_map>

using namespace std;

int count_ways_to_step(int n_steps) {
    // If there are w_(n-1) ways of climbing n-1 steps, w_(n-2) ways of climbing n-2 steps, and w_(n-3) ways of
    // climbing n-3 steps, then the number of ways of climbing n steps is just w_(n-1) + w_(n-2) + w_(n-3).
    // w_0 = 0, w_1 = 1, w_2 = 2. 

    if (n_steps <= 0) return 0;

    unordered_map<int, int> ways_to_step;
    ways_to_step.insert({0, 0});
    ways_to_step.insert({1, 1});
    ways_to_step.insert({2, 2});

    for (int i=3; i<=n_steps; i++) {
        int n_ways = ways_to_step[i-3] + ways_to_step[i-2] + ways_to_step[i-1];
        ways_to_step.insert({i, n_ways});
    }

    return ways_to_step[n_steps];
}

int main() {
    int n_steps = 36;
    cout << "There are " << count_ways_to_step(n_steps) << " ways to climb " << n_steps << " steps." << endl;

    return 0;
}
