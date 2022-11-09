#include <string>
#include <vector>

using namespace std;

struct position {
    int x;
    int y;
};

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<position> pos;
    
    int cnt = 0;
    while (true) { /* 그래프 만들기 */
        position temp = {cnt, k};
        pos.push_back(temp);
        
        if (k == 1) break;
        if (k % 2 == 0) k /= 2;
        else k = k*3 + 1;
        
        cnt++;
    }
    
    for (auto item : ranges) { /* 구간의 넓이 구하기 */
        int a = item[0]; /* 범위의 시작점 */
        int b = item[1]; /* 범위의 끝점 */
        size_t pos_len = pos.size(); /* 그래프의 x축 길이 */
        double area = 0.0; /* 넓이 초기화 */
        
        if (a == 0 && b == 0) { /* 구간 전체의 넓이 */
            for (size_t i=1; i<pos_len; ++i) {
                area += double(abs(pos[i-1].y + pos[i].y)) / 2.0;
            }
        }
        
        else if (a - b > pos.back().x) { /* 구간을 넘어갈 때 */
            area = -1.0;
        }
        
        else {
        /* b는 구간의 마지막부터 시작점으로 이동한다 => pos_len+b가 구하고자 하는 구간 + 1 */
            for (size_t i=a+1; i<pos_len+b; ++i) { 
                area += double(abs(pos[i-1].y + pos[i].y)) / 2.0;
            }
        }
        
        answer.push_back(area);
    }
    
    return answer;
}