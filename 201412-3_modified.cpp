/*
与201412-3.cpp不同的写法，不能AC的原因未知
 */
#include <bits/stdc++.h>
using namespace std;

struct Record {
    string cmd;   // the command to do
    double price; // the price of the stock to buy or sell
    int volume;   // the volume of the stock to buy or sell
    int line;     // cancel the correspond line
    bool deleted;
    long long sum_buy, sum_sell;
    friend bool operator<(const Record &a, const Record &b) {
        return a.price < b.price;
    }
};

vector<Record> v;

int main(void) {
    // freopen("201412-3_input.txt", "r", stdin);
    Record record;
    while (cin >> record.cmd) {
        switch (record.cmd[0]) {
        case 'b':
        case 's':
            cin >> record.price >> record.volume;
            break;
        case 'c':
            cin >> record.line;
            break;
        }
        v.push_back(record);
    }

    // traverse the vector v to cancel the correspond cmd
    for (auto i = v.rbegin(); i != v.rend(); i++) {
        if (i->cmd == "cancel" && !i->deleted) {
            (v.begin() + i->line - 1)->deleted = true;
            i->deleted = true;
        }
    }
    for (auto i = v.begin(); i != v.end(); i++) {
        if (i->deleted)
            v.erase(i);
    }
    // sort
    sort(v.begin(), v.end());
    // sum_buy
    for (auto i = v.rbegin(); i != v.rend(); i++) {
        if (i->cmd[0] == 'b') {
            i->sum_buy = i->volume;
        } else
            i->sum_buy = 0;
        if (i != v.rbegin())
            i->sum_buy += (i - 1)->sum_buy;
    }
    // sum_sell
    for (auto i = v.begin(); i != v.end(); i++) {
        if (i->cmd[0] == 's') {
            i->sum_sell = i->volume;
        } else
            i->sum_sell = 0;
        if (i != v.begin())
            i->sum_sell += (i - 1)->sum_sell;
    }
    //
    auto it = v.begin();
    long long prev = 0;
    for (; it != v.end(); it++) {
        long long volume = min(it->sum_buy, it->sum_sell);
        if (prev > volume)
            break;
        prev = volume;
    }
    it--;
    printf("%.2f %lld", it->price, min(it->sum_buy, it->sum_sell));

    // test
    /* for (int i = 0; i < v.size(); i++) {
        printf("cmd: %s, price: %.2f, volume: %lld, sum_buy: %lld, sum_sell: "
               "%lld\n",
               v[i].cmd.c_str(), v[i].price, v[i].volume, v[i].sum_buy,
               v[i].sum_sell);
    } */
    //
}