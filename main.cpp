#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

const int INF = 1e9;

// ==============================
// 印出矩陣
// ==============================
void printMatrix(const vector<vector<int>>& D) {
    int n = D.size();

    cout << "    ";
    for (int j = 0; j < n; j++) {
        cout << setw(5) << j + 1;
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << setw(4) << i + 1;
        for (int j = 0; j < n; j++) {
            if (D[i][j] >= INF / 2) {
                cout << setw(5) << "INF";
            } else {
                cout << setw(5) << D[i][j];
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

// ==============================
// Floyd-Warshall
// ==============================
vector<vector<int>> floydWarshall(vector<vector<int>> D) {
    int n = D.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (D[i][k] < INF &&
                    D[k][j] < INF &&
                    D[i][k] + D[k][j] < D[i][j]) {

                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    return D;
}

// ==============================
// 主程式
// ==============================
int main() {
    int n = 6; // 節點 1~6

    vector<vector<int>> W(n, vector<int>(n, INF));

    // 對角線設為 0
    for (int i = 0; i < n; i++) {
        W[i][i] = 0;
    }

    // 題目中的邊
    W[0][1] = 3;    // 1 -> 2
    W[0][2] = 5;    // 1 -> 3

    W[2][1] = -2;   // 3 -> 2

    W[1][4] = 7;    // 2 -> 5

    W[2][3] = -5;   // 3 -> 4
    W[2][4] = -5;   // 3 -> 5

    W[1][3] = 2;    // 2 -> 4

    W[3][4] = 6;    // 4 -> 5
    W[3][5] = 10;   // 4 -> 6

    W[4][5] = 8;    // 5 -> 6

    cout << "Initial distance matrix W:\n";
    printMatrix(W);

    vector<vector<int>> D = floydWarshall(W);

    cout << "All-pairs shortest path matrix D:\n";
    printMatrix(D);

    return 0;
}