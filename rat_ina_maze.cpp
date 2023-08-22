#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 'O' && !visited[i][j]);
}

bool solveRatInMaze(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &path, vector<vector<bool>> &visited) {
    if (i == n - 1 && j == m - 1) {
        path[i][j] = 1; // Mark the end cell as part of the path
        return true;
    }

    if (isSafe(i, j, n, m, grid, visited)) {
        path[i][j] = 1; // Mark the current cell as part of the path
        visited[i][j] = true;

        // Try moving right
        if (j + 1 < m && solveRatInMaze(i, j + 1, n, m, grid, path, visited))
            return true;

        // Try moving down
        if (i + 1 < n && solveRatInMaze(i + 1, j, n, m, grid, path, visited))
            return true;

        // Try moving left
        if (j - 1 >= 0 && solveRatInMaze(i, j - 1, n, m, grid, path, visited))
            return true;

        // Try moving up
        if (i - 1 >= 0 && solveRatInMaze(i - 1, j, n, m, grid, path, visited))
            return true;

        // Backtrack
        path[i][j] = 0;
        visited[i][j] = false;
        return false;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> path(n, vector<int>(m, 0)); // Initialize path matrix
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // Initialize visited matrix
    if (solveRatInMaze(0, 0, n, m, grid, path, visited)) {
        // Print the path matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO PATH FOUND" << endl;
    }

    return 0;
}
