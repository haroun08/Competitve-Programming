#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
#define ckmax(a, b) ((a) = max((a), (b)))

using namespace std;

ll const mod = 1e9 + 7;

void solve() {
    ll l, r;
    cin >> l >> r;

     ll highest_bit = 0;
    for (ll i = 0; i < 60; ++i) {
        if ((l & (1LL << i)) != (r & (1LL << i))) {
            highest_bit = i;
        }
    }

     ll a = (1LL << highest_bit) - 1;
    ll b = (1LL << highest_bit);
    ll c = (1LL << highest_bit) | a;

     a = max(a, l);
    b = max(b, l);
    c = max(c, l);
    a = min(a, r);
    b = min(b, r);
    c = min(c, r);

     if (a == b || b == c || a == c) {
         if (a == b) {
            a = l;
        } else if (b == c) {
            c = r;
        } else if (a == c) {
            a = l;
        }
    }

    cout << a << " " << b << " " << c << "\n";
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