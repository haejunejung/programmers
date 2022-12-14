#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int>> copy_dungeons;
bool check[8];
int answer;

void dfs (int cnt, int fatigue) {
    if (answer < cnt) /* 더 많은 던전을 돌게 되면 answer 바꿔주기 */
        answer = cnt;
    
    for (int i = 0; i < copy_dungeons.size(); ++i) {
        if (check[i] || copy_dungeons[i][0] > fatigue) continue; /* 이미 지났던 곳이거나, 최소 필요 피로도가 현재 피로도보다 많다면 pass */
        
        check[i] = true;
        dfs(cnt+1, fatigue - copy_dungeons[i][1]); /* 사용하는 필요도만큼 줄이고 DFS */
        check[i] = false;
    }    
}

int solution(int k, vector<vector<int>> dungeons) {
    /* 초기화 ❗️ */
    answer = 0;
    copy_dungeons = dungeons;
    memset(check, false, 8); 
    
    dfs (0, k);
    return answer;
}