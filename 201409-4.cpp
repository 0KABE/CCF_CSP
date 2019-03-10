#include <bits/stdc++.h>
using namespace std;

struct Point {
    bool ban;
    bool customer;
    int volumn;
    int distance = INT_MAX;
};
int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m, k, d;
const int MAXN = 1001;
Point v[MAXN][MAXN];
queue<pair<int, int>> q;

int main(void) {
    scanf("%d%d%d%d", &n, &m, &k, &d);
    // get shop and push it to queue q
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        q.push(pair<int, int>(x, y));
        v[x][y].distance = 0;
    }
    //

    // get custmer position and mark it in the v
    for (int i = 0; i < k; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        v[x][y].customer = true;
        v[x][y].volumn += c;
    }
    //

    // get the coordinate to be banned
    for (int i = 0; i < d; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x][y].ban = true;
    }
    //

    // BFS
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x_cpy = x + direct[i][0], y_cpy = y + direct[i][1];
            if (x_cpy <= 0 || x_cpy > n || y_cpy <= 0 || y_cpy > n ||
                v[x_cpy][y_cpy].ban)
                continue;

            if (v[x_cpy][y_cpy].distance > v[x][y].distance + 1) {
                v[x_cpy][y_cpy].distance = v[x][y].distance + 1;
                q.push(pair<int, int>(x_cpy, y_cpy));
            }
        }
    }

    // sum
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j].customer)
                ans += v[i][j].distance * v[i][j].volumn;
        }
    }
    printf("%lld", ans);
}