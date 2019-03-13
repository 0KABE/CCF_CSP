#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
vector<int> G[MAXN];
stack<int> S;
bool in_stack[MAXN];
int dfn[MAXN], low[MAXN];
int index, ans;
int n, m;

void tarjan(int u) {
    dfn[u] = low[u] = ++index;
    S.push(u);
    in_stack[u] = true;
    for (auto v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v])
            low[u] = min(
                low[u],
                low[v]); //此处我发现min(low[u],low[v]);也能AC，暂时未明白原因
    }

    if (low[u] == dfn[u]) {
        int cnt = 0;
        while (in_stack[u]) {
            ++cnt;
            in_stack[S.top()] = false;
            S.pop();
        }
        ans += cnt * (cnt - 1) / 2;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }
    printf("%d", ans);
}