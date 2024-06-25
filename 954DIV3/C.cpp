#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map> 
#include <map>


#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
 
using namespace std;
 
 
 
 
void solve() {
        int n, m;
        cin >> n >> m;
 
        string s;
        cin >> s;
 
        vector<int> ind(m);
        for(auto &i: ind) cin >> i;
 
        string c;
        cin >> c;
 
        sort(all(ind));
        ind.erase(unique(all(ind)), ind.end());
 
        sort(all(c));
 
        map<int, char> freq;
        for (int i = 0; i < ind.size(); ++i) {
            freq[ind[i]] = c[i];
        }
        auto assignValue = [&s](int index, char value) {
            if (index >= 0 && index < s.size()) {
                s[index] = value;
            }
        };
 
        for_each(all(freq), [&assignValue](const auto& pair) {
            assignValue(pair.first - 1, pair.second);
        });
 
        cout << s << endl; 
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