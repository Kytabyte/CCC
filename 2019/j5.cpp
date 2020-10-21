#include <bits/stdc++.h>

using namespace std;

/** REMARKABLES:
 * 
 *  This is a naive double-ended bfs could pass all given test cases on CCC,
 *  which is good enough for this problem. However, this cannot pass Batch 4 on
 *  DMOJ.
 * 
 *  Marks: 15/15
 *         15/30 on DMOJ's enlarged test set
 * 
 */

typedef tuple<int, int, string> t3;
pair<string, string> rules[3];
int step;
string src, dst;

vector<unordered_map<string, t3>> bfs(string start, int step, bool reverse = false) {
    vector<unordered_map<string, t3>> q(step+1);
    q[0][start] = {0, 0, ""};

    for (int i = 1; i <= step; i++) {
        for (auto& p : q[i-1]) {
            string cur = p.first;
            // find all neighbours
            for (int j = 0; j < 3; j++) {
                auto& r = rules[j];
                string s = reverse ? r.second : r.first;
                string d = reverse ? r.first : r.second;

                int found = 0;
                while (found != -1) {
                    found = cur.find(s, found);
                    if (found != -1) {
                        string nxt = cur.substr(0, found) + d + cur.substr(found + s.size());
                        q[i][nxt] = {j+1, found+1, cur};
                        found += s.size();
                    } 
                }
            }
        }

        // assert(q[i].size() <= 5e4);
    }

    return q;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    for (int i = 0; i < 3; i++) {
        cin >> s >> t;
        rules[i] = make_pair(s, t);
    }

    cin >> step >> src >> dst;
    assert(step <= 15 && src.size() <= 5 && dst.size() <= 50);

    int head = step / 2, tail = step - head;

    vector<unordered_map<string, t3>> q1 = bfs(src, head), q2 = bfs(dst, tail, true);
    string mid = "";
    for (auto& p : q1.back()) {
        if (q2.back().count(p.first)) {
            mid = p.first;
            break;
        }
    }

    if (!mid.empty()) {
        dst = mid;
        vector<t3> ans1, ans2;
        int rule, pos;
        string prev;
        for (int i = head; i >= 1; i--) {
            tie(rule, pos, prev) = q1[i][dst];
            ans1.push_back(make_tuple(rule, pos, dst));
            dst = prev;
        }

        dst = mid;
        for (int i = tail; i >= 1; i--) {
            tie(rule, pos, prev) = q2[i][dst];
            ans2.push_back(make_tuple(rule, pos, prev));
            dst = prev;
        }

        for (int i = head - 1; i >= 0; i--) {
            tie(rule, pos, prev) = ans1[i];
            cout << rule << ' ' << pos << ' ' << prev << endl;
        }

        for (int i = 0; i < tail; i++) {
            tie(rule, pos, prev) = ans2[i];
            cout << rule << ' ' << pos << ' ' << prev << endl;
        }
    }

    return 0;
}