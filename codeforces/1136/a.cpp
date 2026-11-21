#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ll t; cin >> t;

    vector<ll> maxes(245);
    for (ll m = 1; m <= 244;++m) {
        maxes[m] = 0;
        for (ll c = m - 1; c >= 0; --c) {
            ll cd = c + 1;
            ll a = m - c;
            ll d = 0;
            while (a--) {
                d += cd;
                cd = max((ll) 1, cd - 1);
            }
            maxes[m] = max(maxes[m], d);
        }
    }

    while (t--) {
        ll h; cin >> h;

        auto it = lower_bound(maxes.begin(), maxes.end(), h);
        cout << it - maxes.begin() << "\n";
    }
}

