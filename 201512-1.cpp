#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int i;
    long long total = 0;
    while ((c = getchar())) {
        if (c == '\n')
            break;
        i = c - '0';
        total += i;
    }
    printf("%lld", total);
}