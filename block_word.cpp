#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

string serialize(const vector<string>& stacks) {
    string s;
    for (size_t i = 0; i < stacks.size(); ++i) {
        s += stacks[i];
        if (i + 1 < stacks.size()) s += '|';
    }
    return s;
}

bool is_goal(const vector<string>& state, const vector<string>& goal) {
    return state == goal;
}

void print_state(const vector<string>& st) {
    for (size_t i = 0; i < st.size(); ++i) {
        cout << "S" << i << ": ";
        if (st[i].empty()) cout << "(empty)";
        else for (char c : st[i]) cout << c;
        if (i + 1 < st.size()) cout << "  |  ";
    }
    cout << "\n";
}

int main() {
    vector<string> start = {"ABC", "", ""};
    vector<string> goal = {"", "A", "BC"};
    int nstacks = (int)start.size();
    queue<vector<string>> q;
    unordered_map<string, pair<string, string>> parent;
    unordered_set<string> visited;

    string s_ser = serialize(start);
    q.push(start);
    visited.insert(s_ser);
    parent[s_ser] = {"", "START"};

    bool found = false;
    string goal_ser;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        string cur_ser = serialize(cur);
        if (is_goal(cur, goal)) { found = true; goal_ser = cur_ser; break; }

        for (int i = 0; i < nstacks; ++i) {
            if (cur[i].empty()) continue;
            char top = cur[i].back();
            for (int j = 0; j < nstacks; ++j) {
                if (i == j) continue;
                auto next = cur;
                next[i].pop_back();
                next[j].push_back(top);
                string next_ser = serialize(next);
                if (visited.count(next_ser)) continue;
                visited.insert(next_ser);
                string mv = string("move ") + top + " from S" + to_string(i) + " -> S" + to_string(j);
                parent[next_ser] = {cur_ser, mv};
                q.push(move(next));
            }
        }
    }

    if (!found) {
        cout << "No plan found.\n";
        return 0;
    }

    vector<string> moves;
    string cur = goal_ser;
    while (parent[cur].first != "") {
        moves.push_back(parent[cur].second);
        cur = parent[cur].first;
    }
    reverse(moves.begin(), moves.end());

    cout << "Start state:\n"; print_state(start);
    cout << "Goal state:\n"; print_state(goal);
    cout << "\nPlan (" << moves.size() << " moves):\n";
    for (size_t i = 0; i < moves.size(); ++i)
        cout << i + 1 << ". " << moves[i] << "\n";

    cout << "\nFinal state:\n";
    auto sim = start;
    for (auto &m : moves) {
        char block = m[5];
        int from = m[12] - '0';
        int to = m[18] - '0';
        if (!sim[from].empty() && sim[from].back() == block) {
            sim[from].pop_back();
            sim[to].push_back(block);
        }
    }
    print_state(sim);
}
