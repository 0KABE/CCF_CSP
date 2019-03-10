#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int first, second, degree, parent;
    Node() { first = second = degree = parent = 0; }
};

const int maxn = 20000 + 5;
Node nodes[maxn];
int n, m, ans = -1;

int main() {
    freopen("201503-4_input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 2, u; i <= n + m; ++i) { //可以合起来输入!
        cin >> u;
        nodes[u].degree++;
        nodes[i].parent = u;
    }
    queue<int> Q;
    for (int i = 1; i <= n + m; ++i)
        if (nodes[i].degree == 0)
            Q.push(i);
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        if (now == 1)
            continue;
        int next = nodes[now].first + 1, parent = nodes[now].parent;
        if (nodes[parent].first <= next) {
            swap(nodes[parent].first, nodes[parent].second);
            nodes[parent].first = next;
        } else if (nodes[parent].second < next) {
            nodes[parent].second = next;
        }
        nodes[parent].degree--;
        if (nodes[parent].degree == 0)
            Q.push(parent);
    }
    for (int i = 1; i <= n + m; ++i)
        ans = max(ans, nodes[i].first + nodes[i].second);
    cout << ans;
}
