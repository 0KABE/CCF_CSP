#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int N;
int h[MAXN];

int main(void) {
    scanf("%d", &N);
    while (N--) {
        int t;
        scanf("%d", &t);
        printf("%d ", ++h[t]);
    }
}