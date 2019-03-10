#include <bits/stdc++.h>
using namespace std;

struct Record {
    string cmd;
    bool erase;
    double p;
    int s;
};
vector<Record> v;

int main() {
    // freopen("201412-3_input.txt", "r", stdin);
    Record record;
    while (cin >> record.cmd) {
        if (record.cmd == "cancel") {
            cin >> record.s;
            v[record.s - 1].erase = true;
        } else {
            cin >> record.p >> record.s;
        }
        v.push_back(record);
    }

    set<double> s;
    for (auto i : v) {
        if (i.cmd != "cancel" && !i.erase)
            s.insert(i.p);
    }

    long long sum = 0;
    double p0;
    for (auto i = s.begin(); i != s.end(); i++) {
        double p = *i;
        long long sumb = 0, sums = 0;
        for (auto j = v.begin(); j != v.end(); j++) {
            if (j->cmd == "buy" && !j->erase && j->p >= p)
                sumb += j->s;
            if (j->cmd == "sell" && !j->erase && j->p <= p)
                sums += j->s;

            if (sum <= min(sumb, sums)) {
                sum = min(sumb, sums);
                p0 = p;
            }
        }
    }
    printf("%.2f %lld", p0, sum);
}