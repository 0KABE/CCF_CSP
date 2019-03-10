#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int v[MAXN][MAXN];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i][j]);
        }
        putchar('\n');
    }
}