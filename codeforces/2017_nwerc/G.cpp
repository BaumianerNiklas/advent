#include <bits/stdc++.h>
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

ld deg(ld rad) {
    return rad * 180/M_PI;
}

ld polya(ll x, ll y, int k) {
    ld theta = atan2l(y,x);
    ld delta = abs(theta - midangles[k][0]);
    cout << x << ", " << y << " @ " << deg(theta) << endl;
    for (int i = 1; i < midangles[k].size();++i) {
        if (abs(theta - midangles[k][i]) < delta) delta = abs(theta - midangles[k][i]);
    }

    ld asq = cosl(delta) * cosl(delta) * distsq(x, y);
    DEBUG(deg(delta));
    DEBUG(asq);
    return k * asq * tanl(M_PI / k);
}

int main() {

    for (int k = 3; k <= 8; ++k) {
        int c = k / 2 + (k % 2 != 0);
        for (int i = 0; i < c; ++i) {
            midangles[k].push_back((2*i + 1)*M_PI / k);
        }
    }

    int n; cin >> n;

    ll mind, maxd;
    pll minp, maxp;
    ll x1, y1; cin >> x1 >> y1;
    mind = maxd = x1*x1 + y1*y1;
    minp = maxp = {x1, abs(y1)};

    n--;
    while (n--) {
        ll x, y; cin >> x >> y;
        ll d = distsq(x, y);
        if (d < mind) {
            mind = d;
            minp = {x, abs(y)};
        }
        if (d > maxd) {
            maxd = d;
            maxp = {x,abs(y)};
        }
    }

    ld best = 0;
    ld bestk = 3;
    for (int k = 3; k <= 8; ++k) {
        ld outer = polya(maxp.first, maxp.second, k);
        ld inner = polya(minp.first, minp.second, k);
        DEBUG(outer);
        DEBUG(inner);
        ld score = inner / outer;
        if (score > best) {
            best = score;
            bestk = k;
        }
    }

    cout << bestk << " " << best << endl;
}
