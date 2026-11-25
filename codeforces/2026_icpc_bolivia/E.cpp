#include <iostream>
using namespace std;

using ll = long long;

ll binom(ll n, ll k) {
    if (2 * k > n) k = n - k;

    ll r = 1;
    for (ll i = 1; i <= k; ++i) {
        r *= (n + 1 - i);
        r /= i;
    }

    return r;
}

int main() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    ll len = 1;
    ll seen = 1;
    for (len = 1; seen < n; len += 1) {
        ll next = seen + binom(len + 8, 8);
        if (next >= n) break;
        else seen = next;
    }

    ll d = 1;
    ll i = 1;
    while (i <= len) {
        ll k = 8 - d + 1;
        ll left = binom(len - i + k, k);
        // cout << "i = " << i << ", d = " << d << ", seen = " << seen << ", left = " << left << "\n";
        if (seen + left < n) {
            d++;
            seen += left;
        } else {
            cout << d;
            ++i;
        }
    }

    cout << "\n";
    
}
