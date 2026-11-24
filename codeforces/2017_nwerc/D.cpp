
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;

#define OUT(s) cout << s;
#define OUTLN(s) cout << s << "\n";
#define DEBUG(x) cerr << "[" << __LINE__ << "] " #x " = " << (x) << "\n";

int main() {
    int n; cin >> n;
    vector<string> sentence;

    for (int i = 0;i<n;++i) {
        string w;cin >> w;
        sentence.push_back(w);
    }

    int m;cin>>m;
    ll correct = 1, total = 1;

    unordered_map<string, string> trans;
    unordered_map<string, int> corr_trans;
    unordered_map<string, int> incorr_trans;
    for (int i = 0;i<m;++i) {
        string dutch,eng,corr;
        cin >> dutch >> eng >> corr;
        trans[dutch] = eng;
        if (corr.compare("correct") == 0) {
            corr_trans[dutch]++;
        } else {
            incorr_trans[dutch]++;
        }
    }

    for (auto &w : sentence) {
        correct *= corr_trans[w];
        total *= corr_trans[w] + incorr_trans[w];
    }

    if (total == 1) {
        for (auto &w : sentence) {
            cout << trans[w] << " ";
        }
        cout << "\n" << (correct > 0 ? "correct" : "incorrect") << endl;
        return 0;
    } else {
        cout << correct << " correct\n" << total - correct << " incorrect\n";
    }
}
