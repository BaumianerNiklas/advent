#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

using ilong = long long;
using ulong = unsigned long long;

bool win(int evens, int odds) {
    if (odds % 2 == 0) return true;

    if (odds == 1) return evens != 1;

    return evens >= 1 || odds > 3;
}

void testcase() {
    int n;
    cin >> n;

    int evens = 0, odds = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x % 2) odds++;
        else evens++;
    }

    cout << (win(evens, odds) ? "moggity" : "larpity") << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) testcase();
}
