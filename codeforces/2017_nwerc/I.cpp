#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;

struct app {
    int d, s, i;
};


bool cmp(const app& a, const app& b) {
    return (a.s - a.d) < (b.s - b.d);
}

const int C = 10000 + 1;

int dp[501][C];

int main() {
    int n, cap; cin>>n >> cap;

    vector<app> apps(n);
    for (int i = 0;i<n;++i) {
        int s,d;cin>>d>>s;
        apps[i] = {d,s, i+1};
    }

    sort(apps.begin(), apps.end(), cmp);

    for (int i = n-1; i >= 0; --i) {
        for (int c=1; c<C;++c) {
            int m = max(apps[i].d, apps[i].s);
            if (i == n) {
                dp[i][c] = m <= c;
                continue;
            }

            int d = dp[i+1][c];
            if (m <= c) d = max(d, dp[i+1][c-apps[i].s] + 1);
            dp[i][c] = d;
        }
    }

    int res = dp[0][cap];
    vector<int> order;
    int c = cap;
    while (order.size() < res && c > 0) {
        for (int i=0;i<n;++i) {
            if (dp[i][c] == dp[i+1][c]) continue;

            order.push_back(apps[i].i);
            c -= apps[i].s;
        }
    }
   
    cout<<res<<"\n";
    for (int i=0;i<order.size();++i) cout << order[i] << " \n"[i==order.size()-1];
}