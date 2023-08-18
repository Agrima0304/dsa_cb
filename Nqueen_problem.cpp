#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool IsSafe(int mat[][1000], int i, int j, int n) {
    for (int k = 0; k < n; k++) {
        if (mat[i][k] == 1 || mat[k][j] == 1) {
            return false;
        }
    }
    
    for (int k = i, l = j; k >= 0 && l >= 0; k--, l--) {
        if (mat[k][l] == 1) {
            return false;
        }
    }
    
    for (int k = i, l = j; k >= 0 && l < n; k--, l++) {
        if (mat[k][l] == 1) {
            return false;
        }
    }
    
    return true;
}

bool print(int mat[][1000], int i, int n, int &c) {
    if (i == n) {
        c++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    cout << "{" << i + 1 << "-" << j + 1 << "}" << " ";
                }
            }
        }
        cout << " ";
        return false;
    }
    for (int j = 0; j < n; j++) {
        if (IsSafe(mat, i, j, n)) {
            mat[i][j] = 1;
            bool d = print(mat, i + 1, n, c);
            if (d == true) {
                return true;
            }
            mat[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int mat[1000][1000] = {0};
    int count = 0;
    print(mat, 0, n, count);
    cout << endl;
    cout << count;
    return 0;
}
