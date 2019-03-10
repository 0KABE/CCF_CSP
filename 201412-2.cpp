#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
int N;
int matrix[MAXN][MAXN];

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool down = false;
    for (int d = 0; d < 2 * N; d++) {
        int minimum = max(d - N + 1, 0), maximum = min(d, N - 1);
        if (down)
            for (int i = minimum; i <= maximum; i++) {
                int j = d - i;
                printf("%d ", matrix[i][j]);
            }
        else
            for (int i = maximum; i >= minimum; i--) {
                int j = d - i;
                printf("%d ", matrix[i][j]);
            }
        down = !down;
    }
}
