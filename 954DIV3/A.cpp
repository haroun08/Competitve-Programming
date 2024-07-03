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
 
bool check(vector<int>& v, int mid,int ori)
{
    vector<int>frekbit(31);
    for (int i = 0; i < mid; i++)
    {
        int x = v[i];
 
        for (int j = 30; j >= 0; j--)
        {
            if (x>=(1<<j))
            {
                x -= (1<<j);
                frekbit[j]++;
            }
        }
    }
    int or2 = 0;
    for (int i = 0; i < frekbit.size(); i++)
    {
        if (frekbit[i] > 0)
        {
            or2 += (1 << i);
        }
    }
    if (or2 != ori)
    {
        return false;
    }
    for (int i = 1; i + mid - 1 < v.size(); i++)
    {
        int x = v[i - 1];
        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]--;
                if (frekbit[j] == 0)
                {
                    or2 -= (1 << j);
                }
            }
        }
        x = v[i+mid - 1];
        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]++;
                if (frekbit[j] == 1)
                {
                    or2 += (1 << j);
                }
            }
        }
        if (or2 != ori)
        {
            return false;
        }
    }
    return true;
 
}
 
void solve() {
    int n= 3;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    sort(all(a));
    int mx = *max_element(all(a));
    int mn = *min_element(all(a));
    cout << abs(mx-mn)<< endl;
 
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
