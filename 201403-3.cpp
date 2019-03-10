#include <bits/stdc++.h>
using namespace std;

struct info {
    string cmd;
    bool legal;
    bool exist;
    bool parameter;
};

int N;
info option[128];

int main(void) {
    // get the first line
    char c, prev;
    while ((c = getchar()) != '\n') {
        if (c == ':') {
            option[prev].parameter = true;
        } else {
            option[c].legal = true;
        }
        prev = c;
    }

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        // initialize
        for (int i = 0; i < 128; i++) {
            option[i].exist = false;
            option[i].cmd = "";
        }
        // initialize finished

        // get cmd
        vector<string> parameters;
        string temp;
        cin >> temp;
        parameters.push_back(temp);
        while ((c = getchar()) != '\n') {
            cin >> temp;
            parameters.push_back(temp);
        }
        // get cmd finished

        // check
        int len = parameters.size();
        for (int i = 1; i < len; i++) {
            if (parameters[i][0] != '-')
                break;
            char opt = parameters[i][1];
            if (!option[opt].legal)
                break;

            if (option[opt].parameter) {
                if (++i >= len)
                    break;

                option[opt].cmd = parameters[i];
                option[opt].exist = true;
            } else {
                option[opt].exist = true;
            }
        }
        // check finisheded

        // dispaly
        printf("Case %d:", i);
        for (int i = 0; i < 128; i++) {
            if (option[i].exist) {
                if (option[i].parameter)
                    cout << " -" << char(i) << " " << option[i].cmd;
                else
                    cout << " -" << char(i);
            }
        }
        putchar('\n');
        // display finished
    }
}