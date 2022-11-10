#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    int total[10001] = { };
    int right[10001] = { };
    int cnt_Rtype = 0, cnt_Ltype = 0;
    
    for (auto data : topping) {
        total[data]++;
        right[data]++;
        if (total[data] == 1) cnt_Rtype++;
    }
    
    for (auto data : topping) {
        right[data]--;
        if (right[data] == 0) cnt_Rtype--;
        if (total[data] - right[data] == 1) cnt_Ltype++;
        if (cnt_Rtype == cnt_Ltype) answer++;
    }
    return answer;
}