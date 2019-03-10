#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int n, m;
int Disjoint[MAXN];
struct Edge {
    int first, second;
    int cost;
    friend bool operator>(const Edge &a, const Edge &b) {
        return a.cost > b.cost;
    }
};
priority_queue<Edge, vector<Edge>, greater<Edge>> q;

int Find(int child) {
    if (Disjoint[child] == child)
        return child;

    Disjoint[child] = Find(Disjoint[child]);
    return Disjoint[child];
}

void Union(int a, int b) { Disjoint[a] = Disjoint[b]; }

int main(void) {
    scanf("%d%d", &n, &m);
    // intialize Disjoint Set
    for (int i = 1; i <= n; i++)
        Disjoint[i] = i;
    // input
    for (int i = 0; i < m; i++) {
        Edge e;
        scanf("%d%d%d", &e.first, &e.second, &e.cost);
        q.push(e);
    }
    //

    // Kruskal
    int ans = 0;
    int edges = 0;
    while (edges < n - 1) {
        Edge e = q.top();
        q.pop();

        int a = Find(e.first), b = Find(e.second);
        if (a != b) {
            Union(a, b);
            ans += e.cost;
            edges++;
        }
    }
    printf("%d", ans);
}