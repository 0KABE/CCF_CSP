#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
struct Node {
    int value, count;
    friend bool operator>(const Node &a, const Node &b) {
        if (a.count == b.count)
            return a.value < b.value;
        return a.count > b.count;
    }
};
Node v[MAXN];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        v[temp].value = temp;
        v[temp].count++;
    }
    sort(v, v + sizeof(v) / sizeof(Node), greater<Node>());

    for (int i = 0; i < 1001; i++) {
        if (v[i].count) {
            printf("%d %d\n", v[i].value, v[i].count);
        }
    }
}
