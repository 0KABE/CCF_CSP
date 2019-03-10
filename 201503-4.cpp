/*
Floyd Algorithm
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20005;
// const int MAXN = 9005;

int floyd[MAXN][MAXN];
int n, m;

int main() {
    // freopen("201503-4_input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n + m; i++) {
        for (int j = 1; j <= n + m; j++)
            if (i != j)
                floyd[i][j] = INT_MAX / 10;
            else
                floyd[i][j] = 0;
    }

    for (int i = 2; i <= n; i++) {
        int t;
        scanf("%d", &t);
        floyd[i][t] = 1;
        floyd[t][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int t;
        scanf("%d", &t);
        floyd[i + n][t] = 1;
        floyd[t][i + n] = 1;
    }

    bool update = true;
    while (update) {
        update = false;
        for (int i = 1; i <= n + m; i++) {
            for (int j = 1; j <= n + m; j++) {
                for (int k = 1; k <= n + m; k++) {
                    if (floyd[i][k] + floyd[k][j] < floyd[i][j]) {
                        update = true;
                        floyd[i][j] = floyd[i][k] + floyd[k][j];
                    }
                }
            }
        }
    }
    // test
    // for (int i = 1; i <= n + m; i++) {
    //     for (int j = 1; j <= n + m; j++) {
    //         printf("%d ", floyd[i][j]);
    //     }
    //     putchar('\n');
    // }
    //

    int ans = 0;
    for (int i = 1; i <= n + m; i++) {
        for (int j = i + 1; j <= n + m; j++) {
            ans = max(ans, floyd[i][j]);
        }
    }
    printf("%d", ans);
}