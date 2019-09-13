#include <bits/stdc++.h>
using namespace std;

int priority(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case 'x':
  case '/':
    return 2;
  }
  return -1;
}

void cal(stack<int> &opernd, stack<char> &opertr) {
  int b = opernd.top();
  opernd.pop();
  int a = opernd.top();
  opernd.pop();
  char c = opertr.top();
  opertr.pop();
  switch (c) {
  case '+':
    opernd.push(a + b);
    break;
  case '-':
    opernd.push(a - b);
    break;
  case 'x':
    opernd.push(a * b);
    break;
  case '/':
    opernd.push(a / b);
    break;
  }
}

int N;
int main() {
    // freopen("201903-2.in", "r", stdin);

  scanf("%d", &N);
  while (N--) {
    stack<int> opernd;
    stack<char> opertr;
    int p;
    char t;
    scanf("%d", &p);
    opernd.push(p);
    for (int i = 0; i < 3; ++i) {
      scanf("%c%d", &t, &p);
      if (!opertr.empty() && priority(opertr.top()) >= priority(t)) {
        cal(opernd, opertr);
      }
      opernd.push(p);
      opertr.push(t);
    }
    while (!opertr.empty()) {
      cal(opernd, opertr);
    }
    // printf("%d ", opernd.top());
    printf("%s\n", opernd.top() == 24 ? "Yes" : "No");
  }
}