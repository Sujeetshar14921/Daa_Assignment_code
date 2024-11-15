#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void matrixChainOrder(vector<int>& dims, int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
    cout << "Optimal parenthesization: ";
    printOptimalParenthesization(s, 1, n - 1);
    cout << endl;
}

void printOptimalParenthesization(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParenthesization(s, i, s[i][j]);
        printOptimalParenthesization(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    
    vector<int> dims(n + 1);
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    }

    matrixChainOrder(dims, n + 1);
    return 0;
}
