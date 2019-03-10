#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> u;

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        u.push_back(temp);
    }
    sort(u.begin(), u.end());

    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        if (u[i + 1] - u[i] == 1)
            count++;
    }
    printf("%d", count);
}