#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
#define ckmax(a, b) ((a) = max((a), (b)))

using namespace std;

ll const mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto& i : a){
        cin >> i;
    }
    for(auto& i: b) {
        cin >> i;
    }
    set<int> setA(all(a)),setB(all(b));
    int result = setA.size() + setB.size();
    cout << (result>= 4 ? "YES" : "NO") << endl; 
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