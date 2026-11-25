#include <iostream>
using namespace std;

using ll = long long;

string method(string &w) {
    ll n = w.length();
    string s;
    for(ll i=0;i<n;++i) {
        s.push_back(w[2*i % n]);
    }

    return s;
}

int main() {
    ll n,k; cin>>n>>k;
    string w; cin >> w;

    if (n % 2) {
        if (n == 1) {
            cout << w << "\n";
            return 0;
        }
        
        k = k%(n-1);
        ll base = 1;
        while (k--) base = (base * 2) % n;

        string s;
        for (ll i =0;i<n;++i) {
            s.push_back(w[(i * base) % n]);
        }

        cout << s << "\n";
        return 0;
        // if (n > 1) k = k % (n-1);
        // else k = 0;
    } else {
        k = 2 - k%2;
    }
    
    while (k--) w = method(w);
    cout << w << "\n";
}

