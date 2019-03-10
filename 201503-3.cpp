#include <bits/stdc++.h>
using namespace std;

int days[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int week[2050 - 1850 + 1][13][6][8];

bool isLeap(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    else
        return false;
}

int main(void) {
    int cur_week = 2;
    for (int y = 1850; y <= 2050; y++) {
        bool leap = isLeap(y);
        for (int m = 1; m <= 12; m++) {
            int w_th = 1, start_week = cur_week;
            for (int d = 1; d <= days[leap][m]; d++) {
                week[y - 1850][m][w_th][cur_week++] = d;
                cur_week = (cur_week - 1) % 7 + 1;
                if (cur_week == start_week) {
                    w_th++;
                }
            }
        }
    }

    int a, b, c, y1, y2;
    scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
    if (y1 > y2)
        swap(y1, y2);
    for (int y = y1; y <= y2; y++) {
        if (week[y - 1850][a][b][c] > 0)
            printf("%d/%02d/%02d\n", y, a, week[y - 1850][a][b][c]);
        else
            printf("none\n");
    }
}