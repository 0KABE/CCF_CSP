#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int N;

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        // paint
        for (int r = y1; r < y2; r++) {
            while (v.size() <= r) {
                v.push_back(vector<int>());
            }

            for (int c = x1; c < x2; c++) {
                while (v[r].size() <= c)
                    v[r].push_back(0);

                v[r][c] = 1;
            }
        }
        //
    }

    // count
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            count = (v[i][j] == 1) ? count + 1 : count;
        }
    }
    printf("%d", count);
}