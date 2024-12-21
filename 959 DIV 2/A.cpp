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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(auto &i : a){
        for(auto &j : i) {
            cin >> j;
        }
    }
    if( n * m ==1) {
        cout << -1 << endl;
    }
    else{
        for(int i=0 ; i<n;i++){
            for(int j=0;j<m;j++){
                cout << a[(i + 1) % n][(j + 1) % m] << ' ';
            }
            cout << endl;
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