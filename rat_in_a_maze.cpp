#include <iostream>
using namespace std;

bool rat(char a[1000][1000], int i, int j, int m, int n, int sol[1000][1000]) {
    if (i == m - 1 && j == n - 1) {
        sol[i][j] = 1;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                cout << sol[x][y] << " ";
            }
            cout << endl;
        }
        return true;
    }
    
    sol[i][j] = 1;
    
    if (i + 1 < m && a[i + 1][j] != 'X') {
        if (rat(a, i + 1, j, m, n, sol)) {
            return true;
        }
    }
    
    if (j + 1 < n && a[i][j + 1] != 'X') {
        if (rat(a, i, j + 1, m, n, sol)) {
            return true;
        }
    }
    
    sol[i][j] = 0;
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    char a[1000][1000];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    int sol[1000][1000] = {0}; // Initialize the sol array locally within main
    
    bool check = rat(a, 0, 0, m, n, sol);
    
    if (!check) {
        cout <<-1;
    }
    
    return 0;
}


