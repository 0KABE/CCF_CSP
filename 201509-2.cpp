#include <bits/stdc++.h>
using namespace std;

int days[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool isLeap(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    else
        return false;
}

int main() {
    int y, d;
    cin >> y >> d;
    bool leap = isLeap(y);

    int m = 1;
    while (days[leap][m] < d) {
        d -= days[leap][m++];
    }

    printf("%d\n%d", m, d);
}