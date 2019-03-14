#include <bits/stdc++.h>
using namespace std;

int M[16][11]; // the last line is filled with 1
int B[4][4];

bool crash(int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (M[i + y][j + x] && B[i][j])
                return true;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> M[i][j];
        }
    }
    for (int j = 1; j <= 10; j++)
        M[15][j] = 1; // the last line

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> B[i][j];
        }
    }

    int y, x;
    cin >> x;
    for (y = 0; !crash(x, y); y++) {
        continue;
    }
    --y;
    // printf("x: %d, y: %d\n\n", x, y);
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j <= 10; j++) {
            if (j - x < 4 && j - x >= 0 && i - y < 4 && i - y >= 0) {
                printf("%d ", M[i][j] || B[i - y][j - x]);
            } else {
                printf("%d ", M[i][j]);
            }
        }
        putchar('\n');
    }
}