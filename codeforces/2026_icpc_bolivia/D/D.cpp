#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<int> molds_total(26, 0);
    vector<int> molds_used(26, 0);
    vector<int> molds_used2(26, 0);
    vector<int> molds_cold(26, 0);

    while (n--) {
        string w;
        cin >> w;

        for (int i = 0; i < 26; ++i) {
            molds_cold[i] += molds_used2[i];
            molds_used2[i] = molds_used[i];
            molds_used[i] = 0;
        }

        for (char c : w) {
            int i = c - 'A';

            molds_used[i] += 1;

            if (molds_cold[i] > 0) {
                molds_cold[i]--;
            } else {
                molds_total[i]++;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < 26; ++i) {
        total += molds_total[i];
    }

    cout << total << "\n";
    
}