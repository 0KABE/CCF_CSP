/*
score:90
dfs was replaced with the loop
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
vector<int> G[MAXN];
vector<int> path;
bool vis[MAXN][MAXN];
int n, m;

void dfs() {
    stack<int> S;
    S.push(1);
    while (!S.empty()) {
        int v = S.top();
        int i = 0;
        for (; i < G[v].size(); i++) {
            int w = G[v][i];
            if (!vis[v][w]) {
                vis[v][w] = vis[w][v] = true;
                S.push(w);
                break;
            }
        }
        if (i == G[v].size()) {
            path.push_back(v);
            S.pop();
        }
    }
}

bool check(vector<int> &v) {
    if (v.size() % 2)
        return true;
    else
        return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (auto &i : G) {
        sort(i.begin(), i.end());
    }
    int cnt = count_if(G + 1, G + MAXN + 1, check);
    if (cnt == 0 || (cnt == 2 && check(G[1]))) {
        dfs();
        for (auto it = path.rbegin(); it != path.rend(); it++) {
            printf("%d ", *it);
        }
    } else
        printf("-1");
}