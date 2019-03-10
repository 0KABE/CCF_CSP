#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string target;
    int CaseOption, N;
    cin >> target >> CaseOption >> N;

    if (CaseOption == 0) {
        for (char &c : target)
            c = tolower(c);
    }
    while (N--) {
        string cur;
        string src;
        cin >> cur;
        src = cur;
        if (CaseOption == 0) {
            for (char &c : cur)
                c = tolower(c);
        }

        if (cur.find(target) != string::npos)
            cout << src << endl;
    }
}