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
    int n= 3;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    int mx = *max_element(all(a));
    int mn = *min_element(all(a));
    cout << abs(mx-mn)<< endl;
 
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