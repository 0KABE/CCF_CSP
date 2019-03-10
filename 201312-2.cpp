#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b, c, d, e, f, g, h, i, j;
    char x;
    scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c", &a, &b, &c, &d, &e, &f, &g, &h,
          &i, &x);
    if (x == 'X')
        j = 10;
    else
        j = x - '0';
    if ((a + b * 2 + c * 3 + d * 4 + e * 5 + f * 6 + g * 7 + h * 8 + i * 9) %
            11 ==
        j) {
        printf("Right");
    } else {
        int m = (a + b * 2 + c * 3 + d * 4 + e * 5 + f * 6 + g * 7 + h * 8 +
                 i * 9) %
                11;
        char ch = m == 10 ? 'X' : '0' + m;
        printf("%d-%d%d%d-%d%d%d%d%d-%c", a, b, c, d, e, f, g, h, i, ch);
    }
}