#include <bits/stdc++.h>
using namespace std;

using vc = vector<char>;
using vi = vector<int>;
using ll = long long;

#define PB push_back;
#define OUT(s) cout << s << endl

ll n,s;
vector<ll> w;


int main() {
    cin >> n >> s;
    w.resize(n);
    for (ll i = 0; i<n;++i) {
        cin >> w[i];
    }

    if (s <= 2 || n <= 2) {
        cout << min(n, s) << "\n";
        return 0;
    }

    sort(w.begin(), w.end());
    w.resize(n-2);
    s -= 2;

    ll i1= 0;  ll i2=0;
    vector<ll> v0,v1,v2;

    ll left = s * 3;
    ll c = 2;
    ll i = 0;
    while (left > 0 && i < n - 2) {
        ll m = w[i] % 3;
        ll cost = w[i];
        if (m == 1) {
            if (i2 > i1) {
                cost -= 1;
            } else {
                ll extra = max((ll) 0, i1 - i2);
                if (extra % 2) cost -= 1;
                else cost += 2;
            }
        } else if (m == 2) {
            // if (i1 <= i2) cost += 1;
            // else cost -= 2;
            // if (i1 % 2) cost -= 2;
            // else cost -= 1;
            ll extra = i1 - i2;
            if (extra <= 0) cost += 1;
            else if (extra % 2) cost -= 2;
            else cost += 1;
        }

        // cout << "looking at " << w[i] << " with cost " << cost << ", " << left << " left" << endl;

        if (cost <= left) {
            ++c;
            left -= cost;

            if (m == 1) i1++;
            if (m == 2) i2++;
        }

        ++i;
    }

    cout << c << endl;
}
