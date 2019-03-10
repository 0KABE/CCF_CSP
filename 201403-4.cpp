#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    int count;
};
vector<Node> u;
queue<int> q;
int n, m, k, r;

int main(void) {
    scanf("%d%d%d%d", &n, &m, &k, &r);
    for (int i = 0; i < n + m; i++) {
        Node n;
        scanf("%d%d", &n.x, &n.y);
        n.count = INT_MAX;
        u.push_back(n);
    }

    int size = u.size();
    q.push(0);
    u[0].count = 0;
    while (!q.empty()) {
        int index = q.front();
        q.pop();

        for (int i = 0; i < size; i++) {
            double distance =
                sqrt(pow(u[index].x - u[i].x, 2) + pow(u[index].y - u[i].y, 2));
            if (distance <= r && u[index].count + 1 < u[i].count) {
                u[i].count = u[index].count + 1;
                q.push(i);
            }
        }
    }
    printf("%d", u[1].count - 1);
}