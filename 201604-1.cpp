#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    int ans = 0;
    for (int i = 1; i < v.size() - 1; i++) {
        if (v[i] == min(v[i - 1], min(v[i], v[i + 1])) ||
            v[i] == max(v[i - 1], max(v[i], v[i + 1]))) {
            ++ans;
        }
    }
    cout << ans;
}