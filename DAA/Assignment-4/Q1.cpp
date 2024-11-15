#include <iostream>
#include <vector>
using namespace std;

class NQueen {
public:
    int N;
    vector<vector<int>> board;

    NQueen(int n) : N(n), board(n, vector<int>(n, 0)) {}

    // Check if it's safe to place a queen at board[row][col]
    bool isSafe(int row, int col) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1)
                return false;
        }

        // Check diagonal (upper left)
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1)
                return false;
        }

        // Check diagonal (upper right)
        for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    // Solve the N-Queen problem using backtracking
    bool solveNQueen(int row) {
        if (row == N)
            return true; // All queens placed successfully

        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 1; // Place the queen
                if (solveNQueen(row + 1)) {
                    return true; // Continue to place next queen
                }
                board[row][col] = 0; // Backtrack if placing queen doesn't work
            }
        }
        return false; // No valid position found
    }

    void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << endl;
        }
    }

    void solve() {
        if (solveNQueen(0)) {
            printSolution();
        } else {
            cout << "Solution does not exist." << endl;
        }
    }
};

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    NQueen nq(N);
    nq.solve();
    return 0;
}
