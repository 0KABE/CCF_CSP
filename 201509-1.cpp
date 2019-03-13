#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int cur, prev;
    int count = 1;
    scanf("%d%d", &N, &prev);
    while (--N) {
        scanf("%d", &cur);
        if (cur != prev) {
            prev = cur;
            ++count;
        }
    }
    printf("%d", count);
}