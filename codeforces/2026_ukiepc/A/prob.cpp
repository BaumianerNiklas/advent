#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using ll = long long;
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    unordered_map<char, int> counts = {};
    vector<string> words(n);
    for (int i = 0;i<n;++i) cin >> words[i];

    for (auto &w : words) for (auto c : w) ++counts[c];

    vector<pair<int, char>> cts = {};
    for (auto &entry : counts) cts.push_back({entry.second, entry.first});

    sort(cts.begin(), cts.end(), std::greater<pair<int, char>>());
    cts.resize(k);

    unordered_set<char> keep(k);
    for (auto &[_, ch] : cts) keep.insert(ch);

    for (int i = 0; i < words.size(); ++i) {
        for (auto c : words[i]) {
            if (keep.contains(c)) cout << c;
            else cout << cts[0].second;
        }
        if (i<words.size()-1) cout << " ";
    }
    cout << "\n";
}
