#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

void testcase() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << "-1\n";
        return;
    }

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    swap(a[0], a[3]);

    cout << a[0];
    for (ll i = 1; i < n;++i) cout << " " << a[i];
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) testcase();
}
