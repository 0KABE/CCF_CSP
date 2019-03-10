#include <bits/stdc++.h>
using namespace std;

int N, M;
struct coordinate {
    int x1, x2, y1, y2;
    int order;
};
stack<coordinate> s, buffer;

bool in(int click_x, int click_y, coordinate &check) {
    if (click_x <= check.x2 && click_x >= check.x1 && click_y <= check.y2 &&
        click_y >= check.y1)
        return true;
    else
        return false;
}

int main(void) {
    scanf("%d%d", &N, &M);
    // get
    for (int i = 0; i < N; i++) {
        coordinate temp;
        temp.order = i + 1;
        scanf("%d%d%d%d", &temp.x1, &temp.y1, &temp.x2, &temp.y2);
        s.push(temp);
    }

    //
    for (int i = 0; i < M; i++) {
        coordinate temp;
        int x, y;
        scanf("%d%d", &x, &y);
        for (temp = s.top(), s.pop(); !in(x, y, temp) && !s.empty();
             buffer.push(temp), temp = s.top(), s.pop()) {
            continue;
        }

        if (in(x, y, temp)) {
            printf("%d\n", temp.order);
            while (!buffer.empty()) {
                s.push(buffer.top());
                buffer.pop();
            }
            s.push(temp);
        } else {
            puts("IGNORED");
            s.push(temp);
            while (!buffer.empty()) {
                s.push(buffer.top());
                buffer.pop();
            }
        }
    }
}