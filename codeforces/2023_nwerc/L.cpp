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

int n, k;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> a;

int clamp(int x) {
    if (x < 1) return 1;
    if (x > n) return n;
    return x;
}

void print(int x, int y) {
    cout << x << " " << y << endl;
}

void sink(int x, int y) {
    string s;
    for (int i = x - 5; i <= x + 4; i++) {
        print(clamp(i), y);
        cin >> s;
        if (s.compare("sunk") == 0) {
            k--;
            return;
        }
    }

    for (int i = y - 5; i <= y + 4; i++) {
        print(x, clamp(i));
        cin >> s;
        if (s.compare("sunk") == 0) {
            k--;
            return;
        }
    }
}

void solve() {

    cin >> n >> k;
    if (n < 50) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                print(i, j);
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = ((i + 4) % 5) + 1; j <= n; j += 5) {

                print(i, j);
                string s;
                cin >> s;
                if (s.compare("hit") == 0) {
                    sink(i, j);
                    if (k == 0) return;
                }

            }
        }
    }

}

int main() {
    solve();
}
