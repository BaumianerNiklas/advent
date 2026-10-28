#include <iostream>
#include <string_view>
#include <utility>
#include <string>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

bool matches(string_view s, string_view prefix) {
    int last = s.back() - 'A';
    bool m = s.starts_with(prefix) && s.length() == prefix.length() + 1 && last >= 0 && last <= ('L' - 'A');
    // if (m) cout << s << " matches " << prefix << endl;
    return m;
}

void testcase() {
    ll n,P;
    cin>>n>>P;

    ll score = 0;

    while (n--) {
        string r;
        cin >> r;
        if (matches(r, "WrongProblem")) score += 100;
        else if (matches(r, "SameProblem")) score += 30;
        else if (r == "UnreasonableProblemArrangement") score += 10;
        else if (matches(r, "UnreasonableLimitForProblem")) score += 5;
        else if (matches(r, "WeakTestsForProblem")) score += 3;
        else if (matches(r, "BadProblem")) score++;
    }

    cout << (score > P ? "Joker" : "Judger") << "\n";
}

int main() {
    ll T;
    cin>>T;
    while (T--) testcase();
}
