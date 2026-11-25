#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;

ll rem(ll x, ll m) {
    return ((x%m)+m)%m;
}

void testcase() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i<n;++i) cin >> a[i];

    if (n == 1) { cout << a[0] << "\n"; return; }

    vll pathr(n + 1, 0);
    vll pathl(n + 1, 0);
    pathr[0] = a[0];
    pathl[0] = a[0];
    for (ll i=1;i<=n;++i) {
        pathr[i] = pathr[i-1] + a[i % n];
        pathl[i] = pathl[i-1] + a[n-i];
    }

    ll best = LLONG_MAX;
    for (ll i = 1;i<=n-1;++i) {
        best = min(best, pathr[i] + pathr[i-1] + (n-i-1) * (a[i] + a[rem(i-1,n)]));
        best = min(best, pathl[i] + pathl[i-1] + (n-i-1) * (a[n-i] + a[rem(n-i+1,n)]));
    }

    cout << best << "\n";
}

int main() {
    ll T;
    cin>>T;
    while (T--) testcase();
}
