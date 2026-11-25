#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;

ll PARENT[2001] = {};
ll RANK[2001] = {};
vector<vector<pll>> hulls(2001, vector<pll>());

ll uf_find(ll x) {
    if (PARENT[x] == 0) return x;
    else {
        PARENT[x] = uf_find(PARENT[x]);
        return PARENT[x];
    }
}

ll uf_union(ll a, ll b) {
    ll x = uf_find(a);
    ll y = uf_find(b);

    if (x == y) return x;

    if (RANK[x] > RANK[y]) {
        PARENT[y] = x;
        return x;
    } else if (RANK[x] < RANK[y]) {
        PARENT[x] = y;
        return y;
    } else {
        PARENT[x] = y;
        RANK[y] += 1;
        return y;
    }
}

vector<pll> towns_in_com(ll N, ll com, unordered_map<ll, pll> &town_map) {
    vector<pll> towns = {};
    ll com_union = uf_find(com);
    for (ll i = 1; i <= N; ++i) {
        if (uf_find(i) == com_union) towns.push_back(town_map[i]);
    }

    return towns;
}

ll cross(pll &a, pll &b, pll &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

vector<pll> convex_hull(vector<pll> &pts) {
    sort(pts.begin(), pts.end());

    ll n = pts.size();
    if (n < 3) return pts;

    vector<pll> hull(2*n);
    ll k = 0;

    for (ll i = 0; i < n; ++i) {
        while (k > 1 && cross(hull[k-2], hull[k-1], pts[i]) <= 0) --k;
        hull[k++] = pts[i];
    }
    for (ll i = n - 2, t = k; i >= 0; --i) {
        while (k > t && cross(hull[k-2], hull[k-1], pts[i]) <= 0) --k;
        hull[k++] = pts[i];
    }

    hull.resize(k - 1);
    return hull;
}

ll shoelace(vector<pll> &pts) {
    ll n = pts.size();
    ll a = 0;

    for (ll i = 0; i < n-1; ++i) {
        a += pts[i].first * pts[i + 1].second - pts[i+1].first * pts[i].second;
    }

    a += pts[n-1].first * pts[0].second - pts[0].first * pts[n-1].second;
    return a;
}

int main() {
    ll N, M;
    cin >> N >> M;

    unordered_map<ll, pll> townmap = {};

    for (ll i = 1; i <= N; ++i) {
        ll x, y;
        cin >> x >> y;
        townmap[i] = {x,y};
        hulls[i] = {{x,y}};
    }

    while (M--) {
        ll a,b;
        cin>>a>>b;

        ll x = uf_find(a), y = uf_find(b);
        if (x != y) {
            ll root = uf_union(x, y);
            ll other = (root == x) ? y : x;

            vector<pll> merged = hulls[root];
            for (ll i = 0; i < hulls[other].size(); ++i) {
                merged.push_back(hulls[other][i]);
            }
            hulls[root] = convex_hull(merged);
            hulls[other].clear();
            cout << shoelace(hulls[root]) << "\n";
        } else {
            cout << shoelace(hulls[x]) << "\n";
        }
    }
}
