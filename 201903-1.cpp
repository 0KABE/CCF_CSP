#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 1e5 + 5;
const ll INF = 0x7fffffff;

int N;
ll max = -INF, min = INF;
ll value[MAXN];
int main() {
  // freopen("201903-1.in", "r", stdin);

  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%lld", &value[i]);
    max = std ::max(max, value[i]);
    min = std ::min(min, value[i]);
  }
  printf("%lld ", max);
  if (N & 1) { // odd
    printf("%lld ", value[N / 2 + 1]);
  } else { // even
    if ((value[N >> 1] + value[N >> 1 | 1]) & 1)
      printf("%.1f ", (value[N / 2] + value[N / 2 + 1]) / 2.0);
    else
      printf("%lld ", (value[N / 2] + value[N / 2 + 1]) >> 1);
  }
  printf("%lld\n", min);
}