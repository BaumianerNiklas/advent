#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;

#define OUT(s) cout << s;
#define OUTLN(s) cout << s << "\n";
#define DEBUG(x) cerr << "[" << __LINE__ << "] " #x " = " << (x) << "\n";

int main() {
    int n; cin >> n;
    if (n <= 3) {
        OUTLN(1);
        return 0;
    }
    cout << n-2 << endl;
}
