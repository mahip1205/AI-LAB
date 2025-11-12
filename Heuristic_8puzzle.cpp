#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <cmath>
using namespace std;
const int N = 3; 

int goal[N][N] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

string toStr(int state[N][N]) {
    string s="";
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            s += to_string(state[i][j]);
    return s;
}

bool isGoal(int state[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(state[i][j] != goal[i][j]) return false;
    return true;
}

void printState(int state[N][N]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) cout << state[i][j] << " ";
        cout << endl;
    }
    cout << "-----\n";
}

void copyState(int src[N][N], int dest[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dest[i][j] = src[i][j];
}


int heuristic(int state[N][N]) {
    int dist = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int val = state[i][j];
            if(val != 0) {
                int gx = (val-1)/N;
                int gy = (val-1)%N;
                dist += abs(i-gx) + abs(j-gy);
            }
        }
    }
    return dist;
}

bool BestFirst(int start[N][N]) {
    auto cmp = [](pair<string,int> a, pair<string,int> b){
        return a.second > b.second;
    };

    priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);
    set<string> visited;

    pq.push({toStr(start), heuristic(start)});

    while(!pq.empty()) {
        string current = pq.top().first; pq.pop();

        int state[N][N], k=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                state[i][j] = current[k++] - '0';

        if(isGoal(state)) {
            cout << "Goal Reached (Best First Search)\n";
            printState(state);
            return true;
        }

        visited.insert(current);

        int x,y;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(state[i][j]==0) { x=i; y=j; }

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int m=0;m<4;m++) {
            int nx=x+dx[m], ny=y+dy[m];
            if(nx>=0 && nx<N && ny>=0 && ny<N) {
                int newState[N][N];
                copyState(state,newState);
                swap(newState[x][y], newState[nx][ny]);
                string s = toStr(newState);
                if(!visited.count(s)) pq.push({s, heuristic(newState)});
            }
        }
    }
    return false;
}

int main() {
    int start[N][N] = {
        {1,2,3},
        {4,0,6},
        {7,5,8}
    };

    cout << "Initial State:\n";
    printState(start);

    BestFirst(start);

    return 0;
}
