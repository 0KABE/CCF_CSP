/*
Tree diameter
double BFS/DFS
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20005;
int n, m;
vector<int> v[MAXN];
int visit[MAXN];
int cost = 0;

int bfs(int index) {
    queue<int> q;

    q.push(index);
    while (!q.empty()) {
        index = q.front();
        q.pop();

        for (auto i : v[index]) {
            if (visit[i] == 0) {
                q.push(i);
                visit[i] = visit[index] + 1;
                cost = cost < visit[i] ? visit[i] : cost;
            }
        }
    }
    return index;
}

int main() {
    freopen("201503-4_input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n + m; i++) {
        int t;
        scanf("%d", &t);
        v[i].push_back(t);
        v[t].push_back(i);
    }
    int max_index = bfs(1);
    // cout << "1st: " << max_index << endl;
    memset(visit, 0, sizeof(visit) / sizeof(int));
    max_index = bfs(max_index);
    // cout << "2nd: " << max_index << endl;
    printf("%d", cost);
}