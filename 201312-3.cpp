#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int u[MAXN][MAXN];
int N;

int main(void) {
    scanf("%d", &N);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int temp;
        scanf("%d", &temp);
        u[i][i] = temp;
        ans = max(ans, temp);
    }
    for (int len = 1; len < N; len++) {
        for (int i = 1; i <= N - len; i++) {
            int j = i + len;
            u[i][j] = min(u[i][j - 1], u[j][j]);
            ans = max(u[i][j] * (len + 1), ans);
        }
    }
    printf("%d", ans);
}