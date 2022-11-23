#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;

int BFS (int from, int to, int cnt) {
    for (int i = 0; i < tree[to].size(); ++i) 
    {
        if (tree[to][i] == from) continue;
        
        cnt = BFS (to, tree[to][i], cnt+1);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 0x7fffffff;
    int from, to;
    tree.resize(n+1);
    
    for (auto wire : wires)
    {
        from = wire[0];
        to = wire[1];
        
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    
    for (auto wire : wires) 
    {
        from = wire[0];
        to = wire[1];
        
        int cnt = BFS (from, to, 1);
        answer = min(answer, abs(n-2*cnt));
    }
    return answer;
}