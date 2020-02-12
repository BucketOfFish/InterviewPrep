#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool explore(int robot_x, int robot_y, int n_rows, int n_cols, vector<vector<bool>> *bad_square, vector<pair<int, int>> *path, vector<vector<bool>> *visited) {
    if (robot_x == n_cols-1 && robot_y == n_rows-1)
        return true;
    if ((*visited)[robot_x][robot_y])
        return false;
    if ((*bad_square)[robot_x][robot_y])
        return false;
    (*visited)[robot_x][robot_y] = true;

    vector<pair<int, int>> next_steps;
    if (robot_x+1 < n_cols) next_steps.emplace_back(robot_x+1, robot_y);
    if (robot_y+1 < n_rows) next_steps.emplace_back(robot_x, robot_y+1);
    for (auto step : next_steps) {
        if (explore(step.first, step.second, n_rows, n_cols, bad_square, path, visited)) {
            path->emplace_back(step.first, step.second);
            return true;
        }
    }
    return false;
}

void find_path(int n_rows, int n_cols, vector<vector<bool>> *bad_square) {
    vector<vector<bool>> visited(n_rows, vector<bool>(n_cols, 0));
    int robot_x = 0;
    int robot_y = 0;

    vector<pair<int, int>> path;
    bool found_path = explore(robot_x, robot_y, n_rows, n_cols, bad_square, &path, &visited);
    if (!found_path)
        cout << "Did not find path" << endl;
    else {
        reverse(path.begin(), path.end());
        cout << "Robot's path:" << endl;
        for (auto position : path)
            cout << "{" << position.first << ", " << position.second << "} ";
        cout << endl;
    }
}

int main() {
    int n_rows = 100;
    int n_cols = 100;

    vector<vector<bool>> bad_square(n_rows, vector<bool>(n_cols, 0));
    for (int i=0; i<n_rows; i++) {
        if (i==82) continue;
        bad_square[5][i] = true;
    }

    find_path(n_rows, n_cols, &bad_square);

    return 0;
}
