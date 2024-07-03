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
 
 
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    for (auto &i: h) cin >> i;
    
    int result = h[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result = max(result + 1, h[i]);
    }
 
    cout << result << endl;
 
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