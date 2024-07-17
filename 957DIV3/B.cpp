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
		cin>>n;
		int sum=1000;
		cout<<sum<<" ";
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			sum+=x;
			cout<<sum<<" ";
		}
		cout<<endl;
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