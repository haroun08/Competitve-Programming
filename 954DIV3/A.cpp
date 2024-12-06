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
    vector<int> a(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int max_value = 0;
    for (int i = 1; i <= n; i += 2)
        max_value = max(max_value, a[i]);
    cout << max_value << '\n';
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