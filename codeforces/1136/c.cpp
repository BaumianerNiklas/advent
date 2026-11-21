#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

void test() {
    ll n, x; cin>>n>>x;
    vector<ll> hs(n);
    for (int i=0;i<n;++i) cin >> hs[i];

    sort(hs.begin(), hs.end());
    hs.resize(n-1);

    ll dmg = 0;
    ll spells = 0;
    for (auto h : hs) {
        h -= dmg;
        if (h <= 0) {
            dmg += x;
            continue;
        }
        
        ll s = (h/x) + (h % x > 0);
        dmg += s * x;
        if (s > 1) spells += s - 1;
    }

    cout << spells << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) test();
}

