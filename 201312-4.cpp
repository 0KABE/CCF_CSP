#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MOD = 1000000007;
long long u[MAXN][6];
int N;

int main(void) {
    scanf("%d", &N);
    u[1][0] = 1;
    for (int i = 2; i <= N; i++) {
        u[i][0] = (u[i - 1][0]) % MOD;
        u[i][1] = (u[i - 1][1] * 2 % MOD + u[i - 1][0]) % MOD;
        u[i][2] = (u[i - 1][2] + u[i - 1][0]) % MOD;
        u[i][3] = (u[i - 1][3] * 2 % MOD + u[i - 1][1]) % MOD;
        u[i][4] = (u[i - 1][4] * 2 % MOD + u[i - 1][1] + u[i - 1][2]) % MOD;
        u[i][5] = (u[i - 1][5] * 2 % MOD + u[i - 1][3] + u[i - 1][4]) % MOD;
    }
    printf("%d", u[N][5]);
}