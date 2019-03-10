#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;

int u[MAX];

int main(void) {
    int N;
    scanf("%d", &N);
    while (N--) {
        int temp;
        scanf("%d", &temp);
        u[temp]++;
    }

    int ans = 0;
    for (int i = 0; i < MAX; i++) {
        if (u[ans] < u[i])
            ans = i;
    }
    printf("%d", ans);
}