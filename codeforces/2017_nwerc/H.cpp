#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

ll calc(ll a, ll b, ll c) {
    return a*a + b*b + c*c + 7*min(a, min(b,c));
}

int main() {
    int n;cin>>n;
    while(n--) {
        vector<ll> v(3);
        for (auto &x: v) cin >> x;
        ll w;cin>>w;

        if (w < 67) {
            ll best = -1;
            for (ll a = 0; a<=w;++a) {
                for (ll b = 0; a + b <= w; ++b) {
                    ll c = w - (a+b);
                    best = max(best, calc(v[0]+a, v[1]+b, v[2]+c));
                }
            }
            cout << best << "\n";
            continue;
        }

        ll hi = v[0]; int ihi = 0;
        for (int i=1;i<=2;++i) if (v[i]>hi) hi = v[i], ihi = i;

        v[ihi]+=w;
        cout << calc(v[0],v[1],v[2]) << "\n";
    }
}