#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("201503-4_input.txt", "w", stdout);
    puts("10000 1000");
    for (int i = 2; i <= 10000; i++) {
        printf("%d ", i - 1);
    }
    putchar('\n');
    for (int i = 1; i <= 10000; i++) {
        printf("%d ", i);
    }
}