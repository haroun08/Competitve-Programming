#include <bits/stdc++.h>
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
#define ckmax(a, b) ((a) = max((a), (b)))
 
using namespace std;
 
ll const mod = 1e9 + 7;
 
 
void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    
    vector<vector<int>> b(k);
    for (int i = 0; i < n; i++) {
        b[a[i] % k].push_back(i + 1);  
    }
    
    int res = -1;
    for (int i = 0; i < k; i++) {
        if ((int)b[i].size() == 1) {
            res = b[i][0];
            break;
        }
    }
    
    if (res == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl << res << endl;
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