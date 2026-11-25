

#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

using ilong = long long;
using ulong = unsigned long long;

void testcase() {
    int n;
    cin >> n;

    int min = n + 1, max = 0, ones = 0;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        if (c == '0') continue;

        ones++;
        if (i < min) min = i;
        if (i > max) max = i;
    }

    if (ones == 2) cout << "1\n";
    else cout << max - min << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) testcase();
}
