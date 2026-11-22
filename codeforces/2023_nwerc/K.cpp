
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

using vc = vector<char>;
using vi = vector<int>;
using pi = pair<int, int>;

#define PB push_back;
#define OUT(s) cout << s << endl

int n,a,b,c,d;
vector<vector<int>> grid;

void visit(int x, int y, int m) {
    // cout << n << a << c;
    cout << "visiting " << x << ", " << y << endl;
    // cout << grid.size();
    if (x < 0 || x >= n || y < 0 || y >= n || grid[y][x] == m || grid[y][x] == 2) return;
    if (grid[y][x] == -1) grid[y][x] = m;
    else grid[y][x] = 2;

    if (m == -2 || m == 0) {
        visit(x + a, y + b, 1);
        visit(x + a, y - b, 1);
        visit(x - a, y + b, 1);
        visit(x - a, y - b, 1);

        visit(x + b, y + a, 1);
        visit(x + b, y - a, 1);
        visit(x - b, y + a, 1);
        visit(x - b, y - a, 1);
    }

    if (m == -2 || m == 1) {
        visit(x + c, y + d, 0);
        visit(x + c, y - d, 0);
        visit(x - c, y + d, 0);
        visit(x - c, y - d, 0);

        visit(x + d, y + c, 0);
        visit(x + d, y - c, 0);
        visit(x - d, y + c, 0);
        visit(x - d, y - c, 0);
    }
}

int main() {
    cin >> n>>a>>b>>c>>d;
    for (int i = 0; i<n;++i) {
        vector<int> row(n, -1);
        grid.push_back(row);
    }
    grid[0][0] = -3;
    visit(0, 0, -2);

    int count = 0;
    for (int y = 0; y<n;++y) {
        for (int x=0;x<n;++x) {
            count += (grid[x][y] != -1);
        }
    }

    cout << count << endl;
}
