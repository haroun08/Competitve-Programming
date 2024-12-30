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

#define MAXN 400001

using namespace std;

 int leftBound[MAXN], rightBound[MAXN], prefixSum[MAXN], elementCount[MAXN];

void solve() {
    int n;
    cin >> n;

     for (int i = 1; i <= 2 * n; ++i) {
        prefixSum[i] = 0;
        elementCount[i] = 0;
    }

     for (int i = 1; i <= n; ++i) {
        cin >> leftBound[i] >> rightBound[i];
         if (leftBound[i] == rightBound[i]) {
            prefixSum[leftBound[i]] = 1;
            ++elementCount[leftBound[i]];
        }
    }

     for (int i = 2; i <= 2 * n; ++i) {
        prefixSum[i] += prefixSum[i - 1];
    }

     for (int i = 1; i <= n; ++i) {
        bool isUnique;

        if (leftBound[i] == rightBound[i]) {
             isUnique = (elementCount[leftBound[i]] <= 1);
        } else {
             int totalElementsInRange = rightBound[i] - leftBound[i] + 1;
            int coveredElements = prefixSum[rightBound[i]] - prefixSum[leftBound[i] - 1];
            isUnique = (coveredElements < totalElementsInRange);
        }

        cout << (isUnique ? "1" : "0");
    }

    cout << endl;
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