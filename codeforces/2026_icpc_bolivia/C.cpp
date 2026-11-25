
#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
#include <unordered_set>

using namespace std;

struct logs {
    long long h;
    long long to;
    bool operator<(const logs& o) const { return to < o.to; }
};

long long height(long long l) {
    return l * (l + 1) / 2;
}

int main() {
    long long N, Q;
    cin >> N >> Q;

    set<logs> b{{N, N}};
    long long total = height(N);

    while (Q--) {
        long long i;
        cin >> i;
        
        auto it = b.upper_bound({0, i - 1});
        long long to = it->to;
        long long h = it->h;
        b.erase(it);
        total -= height(h);

        int rel = h - (to - i);
        if (rel > 1) {
            total += height(rel - 1);
            b.insert({rel - 1, i - 1});
        }
        if (rel < to) {
            total += height(h - rel);
            b.insert({h - rel, to});
        }

        cout << total << "\n";
    }

}