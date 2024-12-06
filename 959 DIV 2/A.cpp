#include <bits/stdc++.h>
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
#define ckmax(a, b) ((a) = max((a), (b)))
 
using namespace std;
 
ll const mod = 1e9 + 7;


void solve() {
	int n,m;
    cin >> n >> m;
    int result = 0;
    vector<string> s(n);
    for(auto &i : s) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
      if (m >= gsize(s[i])) {
        m -= gsize(s[i]);
        result++;
      } else {
        break;
      }
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