#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map> 
 
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
 
using namespace std;

void SM(vector<vector<int>>& matrix, int numRows, int numCols) {
    bool hasChanged;
    do {
        hasChanged = false;
 
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                int topNeighbor = 0;
                if (row > 0) {
                    topNeighbor = matrix[row - 1][col];
                }
                
                int leftNeighbor = 0;
                if (col > 0) {
                    leftNeighbor = matrix[row][col - 1];
                }
                
                int bottomNeighbor = 0;
                if (row < numRows - 1) {
                    bottomNeighbor = matrix[row + 1][col];
                }
                
                int rightNeighbor = 0;
                if (col < numCols - 1) {
                    rightNeighbor = matrix[row][col + 1];
                }
                int currentCellValue = matrix[row][col];
                int maxNeighbor = max(topNeighbor, max(leftNeighbor, max(bottomNeighbor, rightNeighbor)));
 
                if (currentCellValue > maxNeighbor) {
                    matrix[row][col] = maxNeighbor;
                    hasChanged = true;
                }
            }
        }
    } while (hasChanged);
}
 
 
void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }
 
        SM(matrix, n, m);
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
  }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}