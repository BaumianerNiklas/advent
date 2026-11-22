#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

using vc = vector<char>;
using vi = vector<int>;

#define PB push_back;
#define OUT(s) cout << s << endl

int main() {
    vector<vector<bool>> agenda(7);

    for (int d = 0; d < 7; ++d) {
        for (int h = 0; h < 24; ++h) {
            char c; cin >> c;
            agenda[d].push_back(c == '.');
        }
    }
    int d, h; cin >> d>>h;
    vector<bool> s(7);

    for (int i = 6; i >= 7 - d; --i) {
        s[i] = true;
    }

    long double M = 0;
    do {
        vi hours(24);
        hours.reserve(24);
        for (int cd = 0; cd < 7; ++cd) {
            if (!s[cd]) continue;

            for (int i = 0; i < 24; ++i) {
                hours[i] += agenda[cd][i];
            }
        }
        sort(hours.begin(), hours.end(), greater<int>{});
        int taken = 0;
        for (int i = 0; i < h; ++i) {
            taken += hours[i];
        }

        M = max(M, (long double) taken / (h * d));
    } while(next_permutation(s.begin(), s.end()));

    cout << M << "\n";
}
