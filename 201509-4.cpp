/*
floyd algorithm
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
bool A[MAXN][MAXN];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        A[i][i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        A[a][b] = 1;
    }

    // floyd
    bool update = true;
    while (update) {
        update = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i][j] == 1)
                    continue;
                for (int k = 1; k <= n; k++) {
                    if (A[i][j] == 0 && A[i][k] == 1 && A[k][j] == 1) {
                        update = true;
                        A[i][j] = 1;
                    }
                }
            }
        }
    }
    //
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (A[i][j] == 1 && A[j][i] == 1)
                ++count;
        }
    }
    printf("%d", count);
}