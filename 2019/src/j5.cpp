#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, string> t3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<string, string> rules[3];
    string s, t;
    for (int i = 0; i < 3; i++) {
        cin >> s >> t;
        rules[i] = make_pair(s, t);
    }

    int step;
    string src, dst;
    cin >> step >> src >> dst;

    vector<unordered_map<string, t3>> q(step+1);
    q[0][src] = {0, 0, ""};

    for (int i = 1; i <= step; i++) {
        for (auto& p : q[i-1]) {
            string cur = p.first;
            // find all neighbours
            for (int j = 0; j < 3; j++) {
                auto& r = rules[j];
                int found = 0;
                while (found != string::npos) {
                    found = cur.find(r.first, found);
                    if (found != string::npos) {
                        string nxt = cur.substr(0, found) + r.second + cur.substr(found + r.first.size());
                        q[i][nxt] = {j+1, found+1, cur};
                        found += r.first.size();
                    } 
                }
            }
        }
    }

    if (q.back().count(dst)) {
        vector<t3> ans;
        int rule, pos;
        string prev;
        for (int i = step; i >= 1; i--) {
            tie(rule, pos, prev) = q[i][dst];
            ans.push_back(make_tuple(rule, pos, dst));
            dst = prev;
        }

        for (int i = step - 1; i>= 0; i--) {
            tie(rule, pos, prev) = ans[i];
            cout << rule << ' ' << pos << ' ' << prev << endl;
        }
    }

    return 0;
}