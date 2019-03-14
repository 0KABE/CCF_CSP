/*
AC
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 1;
struct Node {
    int r, c;
    int t;
};
int direct[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> dangerous[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, t;

Node BFS() {
    Node node = {1, 1, 0};
    queue<Node> Q;
    Q.push(node);
    vis[1][1] = true;
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        if (node.r == n && node.c == m)
            break;
        vis[node.r][node.c] = false;

        for (int i = 0; i < 4; i++) {
            int r = node.r + direct[i][0], c = node.c + direct[i][1];
            if (r < 1 || r > n || c < 1 || c > m)
                continue;
            if ((node.t + 1 >= dangerous[r][c].first &&
                 node.t + 1 <= dangerous[r][c].second) ||
                vis[r][c])
                continue;
            vis[r][c] = true;
            Q.push(Node{r, c, node.t + 1});
        }
    }
    return node;
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0, r, c, a, b; i < t; i++) {
        scanf("%d%d%d%d", &r, &c, &a, &b);
        dangerous[r][c].first = a;
        dangerous[r][c].second = b;
    }

    Node node = BFS();
    printf("%d", node.t);
}
