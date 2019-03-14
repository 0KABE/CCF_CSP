#include <bits/stdc++.h>
using namespace std;

string CurPath;
int p;
stack<string> path, source;

int main() {

    scanf("%d\n", &p);

    // get current path
    string s;
    getline(cin, s);
    std::size_t start, end = 0;
    while ((start = s.find_first_not_of('/', end)) != string::npos) {
        end = s.find_first_of('/', start);
        source.push(s.substr(start, end - start));
    }

    while (p--) {
        getline(cin, s);
        if (!s.empty() && s[0] == '/')
            path = stack<string>();
        else
            path = source;

        std::size_t start, end = 0;
        while ((start = s.find_first_not_of('/', end)) != string::npos) {
            end = s.find_first_of('/', start);
            string sub = s.substr(start, end - start);
            if (sub == ".") {
                ;
            } else if (sub == "..") {
                if (!path.empty())
                    path.pop();
            } else {
                path.push(sub);
            }
        }

        // get ans
        string ans;
        while (!path.empty()) {
            ans = "/" + path.top() + ans;
            path.pop();
        }
        if (ans.size() == 0)
            ans = "/";
        cout << ans << endl;
    }
}