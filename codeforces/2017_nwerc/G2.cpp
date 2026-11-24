#include <bits/stdc++.h>
#include <cmath>
using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;

using pll = pair<ll, ll>;

#define OUT(s) cout << s;
#define OUTLN(s) cout << s << "\n";
#define DEBUG(x) cerr << "[" << __LINE__ << "] " #x " = " << (x) << "\n";

ll distsq(ll x, ll y) {
    return x*x + y*y;
}

vector<vector<ld>> midangles(9);

int main() {

    for (int k = 3; k <= 8; ++k) {
        int c = k / 2 + (k % 2 != 0);
        for (int i = 0; i < c; ++i) {
            midangles[k].push_back((2*i + 1)*numbers::pi / k);
        }
    }

    int n; cin >> n;
    vector<pll> pts(n);
    for (auto &p : pts) {
        ll x,y; cin >> x >> y;
        p = {x, abs(y)};
    }

    ld best = -1;
    int bestk = 3;
    for (int k = 3; k <= 8; ++k) {
        ld inner = INFINITY;
        ld outer = 0;
        for (auto &[x, y] : pts) {
            ld theta = atan2l(y,x);
            ld delta = abs(theta - midangles[k][0]);
            for (int i = 1; i < midangles[k].size();++i) {
                if (abs(theta - midangles[k][i]) < delta) delta = abs(theta - midangles[k][i]);
            }

            ld a = cosl(delta) * sqrt(distsq(x, y));
            if (a < inner) inner = a;
            if (a > outer) outer = a;
        }

        ld score = (inner/outer)*(inner/outer);
        if (score > best) {
            best = score;
            bestk = k;
        }
    }

    cout << fixed << setprecision(15) << bestk << " " << best << endl;
}
