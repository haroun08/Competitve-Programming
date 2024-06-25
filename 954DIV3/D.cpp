#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include<climits>
#include <functional> 
#include <vector>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    vector<vector<long long>> dp(n, vector<long long>(n, -1));
 
    auto calc = [](long long a, long long b, char op) -> long long {
        return (op == '+') ? a + b : a * b;
    };
 
    function<long long(int, int)> dfs = [&](int pos, int cnt) -> long long {
        if (cnt == 0) {
            return stoll(s.substr(pos));
        }
 
        if (dp[pos][cnt] != -1) {
            return dp[pos][cnt];
        }
 
        long long res = LLONG_MAX;
        for (int i = pos; i < s.size() - cnt; ++i) {
            long long num1 = stoll(s.substr(pos, i - pos + 1));
            
            // Recursively calculate the result for the remaining part of the string
            long long num2 = dfs(i + 1, cnt - 1);
 
            // Calculate the result using both possible operations and update the minimum result
            long long addResult = calc(num1, num2, '+');
            long long mulResult = calc(num1, num2, '*');
            res = min(res, min(addResult, mulResult));
        }
 
        return dp[pos][cnt] = res;
    };
 
    long long result = dfs(0, n - 2);
    cout << result << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}