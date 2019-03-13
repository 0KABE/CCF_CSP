#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
int m, n, q;
char v[maxn][maxn];
bool vis[maxn][maxn];

void line(int x1, int y1, int x2, int y2) {
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);
    if (x1 == x2) {
        for (int i = y1; i <= y2; i++) {
            if (v[i][x1] == '-')
                v[i][x1] = '+';
            else
                v[i][x1] = '|';
        }
    } else {
        for (int j = x1; j <= x2; j++) {
            if (v[y1][j] == '|')
                v[y1][j] = '+';
            else
                v[y1][j] = '-';
        }
    }
}

int direct[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void f(int x, int y, char c) {
    if (x < 0 || x >= m || y < 0 || y >= n || v[y][x] == '-' ||
        v[y][x] == '|' || v[y][x] == '+' || vis[y][x])
        return;
    v[y][x] = c;
    vis[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int t_x = x + direct[i][0], t_y = y + direct[i][1];
        f(t_x, t_y, c);
    }
}

int main() {
    scanf("%d%d%d", &m, &n, &q);
    memset(v, '.', sizeof(v));
    for (int i = 0; i < q; i++) {
        int x, a, b, c, d;
        char ch;
        scanf("%d", &x);
        switch (x) {
        case 0:
            scanf("%d%d%d%d", &a, &b, &c, &d);
            line(a, b, c, d);
            break;
        case 1:
            scanf("%d%d %c", &a, &b, &ch);
            memset(vis, 0, sizeof(vis));
            f(a, b, ch);
            break;
        }
    }
    // output
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            printf("%c", v[i][j]);
        }
        putchar('\n');
    }
}