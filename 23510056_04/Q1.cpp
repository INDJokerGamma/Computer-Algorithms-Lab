#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplyNaive(vector<vector<int>> A, vector<vector<int>> B, int n) {
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {           // Row of A
        for (int j = 0; j < n; j++) {       // Column of B
            for (int k = 0; k < n; k++) {   // Multiply
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    vector<vector<int>> C = multiplyNaive(A, B, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}
