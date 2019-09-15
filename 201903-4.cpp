#include <bits/stdc++.h>
using namespace std;

#define clr(x) memset(x, 0, sizeof(x))

const int MAXN = 1e4 + 5;

struct Node {
  char optr;
  int target;
};

Node msgs[MAXN][10];
int msg_cnt[MAXN], msg_pos[MAXN];

int T, N;
int main() {
  // freopen("201903-4.in", "r", stdin);

  scanf("%d%d", &T, &N);
  while (T--) {
    clr(msgs);
    clr(msg_cnt);
    clr(msg_pos);

    char opertr, c;
    int target, cnt;
    queue<pair<int, int>> q;
    int q_size = 0; // need to manual maintenance the size of q avoiding the
                    // time limit out
    for (int i = 0; i < N; ++i) {
      do {
        cnt = scanf(" %c%d%c", &msgs[i][msg_cnt[i]].optr,
                    &msgs[i][msg_cnt[i]].target, &c);
        if (!msg_cnt[i] && msgs[i][0].optr == 'S') {
          q.push(pair<int, int>(i, msgs[i][msg_cnt[i]].target));
          ++q_size;
        }
        ++msg_cnt[i];
      } while (c != '\n' && cnt == 3);
    }

    int process_cnt = N;
    int pos = 0;
    while (process_cnt && !q.empty() && pos++ < q_size) {
      auto cur = q.front();
      q.pop();
      --q_size;
      if (cur.first == msgs[cur.second][msg_pos[cur.second]].target) {
        if (++msg_pos[cur.first] < msg_cnt[cur.first]) {
          if (msgs[cur.first][msg_pos[cur.first]].optr == 'S') {
            q.push(pair<int, int>(cur.first,
                                  msgs[cur.first][msg_pos[cur.first]].target));
            ++q_size;
          }
        } else {
          --process_cnt;
        }

        if (++msg_pos[cur.second] < msg_cnt[cur.second]) {
          if (msgs[cur.second][msg_pos[cur.second]].optr == 'S') {
            q.push(pair<int, int>(
                cur.second, msgs[cur.second][msg_pos[cur.second]].target));
            ++q_size;
          }
        } else {
          --process_cnt;
        }

        pos = 0;
      } else {
        q.push(cur);
        ++q_size;
      }
    }

    if (process_cnt || !q.empty()) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
}