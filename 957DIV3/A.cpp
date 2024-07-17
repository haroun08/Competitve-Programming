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
    vector<int> a(3);
    for(auto &i : a) cin >> i;
    for(int i=0;i<5;i++){
        (*min_element(all(a)))++;
    }
    cout << a[0]*a[1]*a[2]<< endl;  
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