#include <bits/stdc++.h>
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
#define ckmax(a, b) ((a) = max((a), (b)))
 
using namespace std;
 
ll const mod = 1e9 + 7;
 
 
void solve() {
    int n ;
    cin >> n  ;
    for(int i= 1,curr = 1;; i++,curr = curr *2 +2){
        if(curr >=n){
            cout << i << endl;
            break;
        }
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