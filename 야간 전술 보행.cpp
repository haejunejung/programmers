#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define work true
#define rest false

bool compare (vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int answer = 0;
    // 야간 전술 보행은 1m/s의 일정한 속도로 나아갈 수 있다
    // 경비병들은 일정 시간 근무 후 일정 시간 동안 휴식하고 감시하는 구간은 서로 겹치지 않는다
    // 화랑이는 쉬지 않고 전진하며, 출발할 때 모든 경비병들이 동시에 근무 시작
    int scope_len = scope.size();
    int times_len = times.size();
    
    while (answer < distance) {
        answer++;
        bool Iswork = rest;
        
        for (int i=0; i<scope_len; ++i) {
            int start = min(scope[i][0], scope[i][1]);
            int end = max(scope[i][0], scope[i][1]);
            if (answer >= start && answer <= end) {
                int temp = answer % (times[i][0] + times[i][1]);
                if (temp > 0 && temp <= times[i][0]) Iswork = work;
                else Iswork = rest;
            }
        }
        
        if (Iswork == work) break;
    }
    return answer;
}