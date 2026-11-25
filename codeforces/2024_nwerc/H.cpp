#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >>n;

    ll c,d;
    cout << "? " << n << " 1\n";
    cin >> c;
    if (c == n) {
        cout << "! " << n << " 1\n";
        return 0;
    }
    cout << "? " << n - c << " 1\n";
    cin>>d;

    cout << "! " << c << " " << d << "\n";
}

