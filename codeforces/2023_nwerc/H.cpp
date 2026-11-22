#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;

using vc = vector<char>;
using vi = vector<int>;
using pi = pair<int, int>;


#define PB push_back;
#define F first;
#define S second;
#define OUT(s) cout << s

int n;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> a;

void solve() {
    cin >> n;
    int ones = 0;
    while (n--) {
        int t;
        cin >> t;
        if (t == 1) {
            ones++;
        } else {
            a.emplace(t, to_string(t));
        }
    }

    while (ones > 1) {
        if (a.empty()) {
            a.emplace(1, "1");
            ones--;
        } else {
            auto m = a.top();
            if (m.first <= 2) {
                a.pop();
                m.second = "(" + m.second + "+1)";
                m.first++;
                ones--;
                a.push(m);
            } else {
                a.emplace(1, "1");
                ones--;
            }
        }
    }

    if (ones == 1) {
        if (!a.empty()) {
            auto m = a.top();
            a.pop();
            m.second = "(" + m.second + "+1)";
            m.first++;
            a.push(m);
        } else {
            a.emplace(1, "1");
        }
    }

    auto t = a.top();
    a.pop();

    OUT(t.second);
    while (!a.empty()) {
        t = a.top();
        a.pop();
        OUT("*" + t.second);
    }
    cout << endl;

}

int main() {
    solve();
}
