// 라이언 vs 어피치
// 한 선수가 연속 우승보다 다양한 선수들이 양궁대회에서 우승하기를 원한다
// 전 대회 우승자 라이언에게 불리하게 => 
// 1. 어피치가 다 쏘고 라이언이 쏜다
// 2. 같은 점수를 같은 발 수 맞춰도 어피치가 점수를 가져간다
// 3. 최종 점수가 같을 경우 어피치가 우승자가 된다 
// 현재 상황 -> 어피치가 다 쏜 후, 라이언이 쏠 차례
// n 발의 화살을 어떤 과녁 점수에 맞혀야 하는지 구하려 한다
// 어떤 과녁 점수에 맞혀야 하는지를 10점부터 0점까지 순서대로 정수 배열에 담아 retrun
// 만약 라이언이 우승할 수 없는 경우 -1 return 
// 라이언이 가장 큰 점수 차이로 우승할 수 있는 방법이 여러 가지 일 경우, 가장 낮은 점수를 더 많이 맞힌 경우를 return
#include <string>
#include <vector>

using namespace std;

vector<int> answer; /* 정답을 넣을 vector */
int maxdiff; /* 라이언과 어피치의 차이의 최댓값 */
bool cmp(vector<int> ryan) { /* 차이가 똑같을 때, 더 낮은 점수가 많은 것이 정답이 되어야 한다는 조건 */
    for (int i=10; i>=0; --i) {
        if (ryan[i] > answer[i]) return true;
        else if (ryan[i] < answer[i]) return false;
        else continue;
    }
}

void CheckAnswer (vector<int> ryan, vector<int> apeach) { /* Answer인지 check */
    int ryanScore = 0;
    int apeachScore = 0;
    
    for (int i=0; i<=10; ++i) {
        if (ryan[i] > apeach[i]) ryanScore += 10 - i;
        else if (apeach[i] > 0) apeachScore += 10 - i;
    }
    
    int diff = ryanScore - apeachScore;
    if (diff > 0 && maxdiff <= diff) {
        if (maxdiff == diff && !cmp(ryan)) return;
        maxdiff = diff;
        answer = ryan;
    }
}

void dfs (int idx, int arrow, vector<int> ryan, vector<int> apeach) {
    if (idx == 11 || arrow == 0) { /* 0점까지 모두 돌았거나, 화살을 모두 쐈을 경우 종료 */
        ryan[10] = arrow; /* 0점까지 모두 돌았는데 남은 화살들은 모두 마지막에 들어감. 화살을 모두 쏘면 arrow가 0임. */
        CheckAnswer (ryan, apeach);
        ryan[10] = 0; /* 전 상태로 돌려주기 (백트래킹) */
        return;
    }
    
    if (arrow - apeach[idx] > 0) {
        ryan[idx] = apeach[idx] + 1;
        dfs(idx+1, arrow-(apeach[idx]+1), ryan, apeach);
        ryan[idx] = 0; /* 백트래킹 */
    }
    
    dfs(idx+1, arrow, ryan, apeach); /* 0발 쏘고 넘어가는 경우 */
}

vector<int> solution(int n, vector<int> info) {
    maxdiff = 0;
    vector<int> ryan(11, 0); /* 라이언은 모두 0점으로 초기화 */
    vector<int> apeach = info; /* 이름으로 편하게 표현하기 위해서 apeach라 표현 */
    dfs (0, n, ryan, apeach);
    
    if (answer.empty()) { /* 만약, answer가 하나도 없었다면 -1로 return */
        answer.push_back(-1);
    }
    return answer;
}