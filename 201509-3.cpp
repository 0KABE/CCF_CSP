/*
time out
score: 90
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int m, n;
string doc[MAXN];
map<string, string> dic;

int main() {
    scanf("%d%d\n", &m, &n);
    for (int i = 0; i < m; i++) {
        getline(cin, doc[i]);
    }
    for (int i = 0; i < n; i++) {
        string key, value;
        cin >> key;
        getline(cin, value);

        std::size_t start = value.find('\"');
        std::size_t end = value.find('\"', start + 1);
        value = value.substr(start + 1, end - start - 1);
        dic.insert(pair<string, string>(key, value));
    }

    // replace
    for (int i = 0; i < m; i++) {
        std::size_t start, end;
        while ((start = doc[i].find("{{ ")) != string::npos) {
            end = doc[i].find(" }}", start + 1);
            string key = doc[i].substr(
                start + 3, end - start - 3); //{{ abc }} start=0, end=6
            string value = dic.count(key) > 0 ? dic[key] : "";
            doc[i].replace(start, end - start + 3, value);
        }
        printf("%s\n", doc[i].c_str());
    }
}