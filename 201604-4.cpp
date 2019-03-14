/* 
score 10
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 1;
struct Node {
    bool dangerous;
    int low, high;
    int t;
} V[MAXN][MAXN];
int direct[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, t;

void bfs() {
    queue<pair<int, pair<int, int>>> q;
    q.push(pair<int, pair<int, int>>(1, pair<int, int>(1, 1)));
    int t = 0;
    bool over = false;
    int order = 0;
    while (!over) {
        t = q.front().second.second == order ? t : t + 1;
        int r = q.front().first, c = q.front().second.first;
        order = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r_cpy = r + direct[i][0], c_cpy = c + direct[i][1];
            if (r_cpy < 1 || r_cpy > n || c_cpy < 1 || r_cpy > m)
                continue;

            if (!V[r_cpy][c_cpy].dangerous ||
                (V[r_cpy][c_cpy].dangerous &&
                 (t < V[r_cpy][c_cpy].low || t > V[r_cpy][c_cpy].high))) {
                V[r_cpy][c_cpy].t = t;
                q.push(pair<int, pair<int, int>>(
                    r_cpy, pair<int, int>(c_cpy, order + 1)));
            }
            if (r_cpy == n && c_cpy == m) {
                V[n][m].t = t;
                over = true;
                break;
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0, r, c, a, b; i < t; i++) {
        scanf("%d%d%d%d", &r, &c, &a, &b);
        V[r][c].dangerous = true;
        V[r][c].low = a;
        V[r][c].high = b;
    }

    bfs();

    printf("%d", V[n][m].t);
}