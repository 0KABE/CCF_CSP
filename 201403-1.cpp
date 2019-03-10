#include <bits/stdc++.h>
using namespace std;

const int MAX = 2002;
int u[MAX];
int N;

int main(void) {
    scanf("%d", &N);
    while (N--) {
        int temp;
        scanf("%d", &temp);
        u[temp + 1000]++;
    }

    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (u[i] == 1 && u[2000 - i] == 1)
            count++;
    }
    printf("%d", count);
}