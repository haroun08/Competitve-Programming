#include <bits/stdc++.h>
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
#define ckmax(a, b) ((a) = max((a), (b)))
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    string s,t;
    cin >> s >> t;
 
 
    for(int i=0 ; i< gsize(s) && s[i]== '0' ; i++ ){
        if(t[i] != '0'){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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