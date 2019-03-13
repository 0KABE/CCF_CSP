#include <bits/stdc++.h>
using namespace std;

const int maxn = 31;
int v[maxn][maxn];
bool d[maxn][maxn];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int start = 0;
        int j;
        for (j = 1; j < m; j++) {
            if (v[i][j - 1] == v[i][j])
                cnt++;
            else {
                if (cnt >= 3) {
                    for (int k = start; k < j; k++) {
                        d[i][k] = true;
                    }
                }
                cnt = 1;
                start = j;
            }
        }
        if (cnt >= 3) {
            for (int k = start; k < j; k++) {
                d[i][k] = true;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int cnt = 1;
        int start = 0;
        int i;
        for (i = 1; i < n; i++) {
            if (v[i - 1][j] == v[i][j])
                cnt++;
            else {
                if (cnt >= 3) {
                    for (int k = start; k < i; k++) {
                        d[k][j] = true;
                    }
                }
                cnt = 1;
                start = i;
            }
        }
        if (cnt >= 3) {
            for (int k = start; k < i; k++) {
                d[k][j] = true;
            }
        }
    }

    // output
    // puts("\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j]) {
                printf("0 ");
            } else {
                printf("%d ", v[i][j]);
            }
        }
        putchar('\n');
    }
}