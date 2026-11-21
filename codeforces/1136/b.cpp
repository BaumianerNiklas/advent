#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int x,y,m;
        cin >> x >> y >> m;
        string spell; cin >> spell;

        int M = 0;
        for (int s = 0; s <= m; ++s) {
            int p1 = x;
            int p2 = y;
            for (int i = 0; i < s; ++i) {
                if (spell[i] == '+') {
                    if (p2 >= 1) p2++;
                    else p2++, p1--;
                } else {
                    if (p2 >= 2) p2--, p1++;
                    else if (p1 >= 1) p1--;
                    else p2--, p1++;
                }
            }
            M = max(M, p1 + p2);
        }

        cout << M << "\n";
    }
}

