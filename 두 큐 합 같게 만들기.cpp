// 생각해야 하는 상황 : 어떤 방법으로도 각 큐의 원소 합을 같게 만들 수 없는 경우
// 모든 원소의 합 / 2인 개수가 2개가 만들어져야 한다.
// 1. (sum1 + sum2) % 2 == 1인 경우
// 2. answer == 2 * (queue1.size() + queue2.size())

// 풀이1 -> TC 24 시간초과 => vector의 erase 연산이 시간이 많이 드는 것을 확인
// vector가 아닌 queue로 풀어야겠다고 생각이 들어 풀이2로 풀었더니 정답이 나왔다

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pop_front(std::vector<int, std::allocator<int>> &v) {
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum1 = 0, sum2 = 0;
    for (auto val : queue1) {
        sum1 += val;
    }
    
    for (auto val : queue2) {
        sum2 += val;
    }
    
    if ((sum1 + sum2) % 2 == 1) return -1;
    
    while (true) {
        if (answer == 2 * (queue1.size() + queue2.size())) {
            answer = -1;
            break;
        }
        
        int temp;
        if (sum1 > sum2) {
            temp = queue1.front();
            pop_front(queue1);
            sum1 -= temp;
            
            sum2 += temp;
            queue2.push_back(temp);
        }
        
        else if (sum1 < sum2) {
            temp = queue2.front();
            pop_front(queue2);
            sum2 -= temp;
            
            sum1 += temp;
            queue1.push_back(temp);
        }
        
        else break; 
        
        answer++;
    }
    
    return answer;
}


// 풀이 2
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum1 = 0, sum2 = 0;
    queue <int> q1, q2;
    for (auto val : queue1) {
        sum1 += val;
        q1.push(val);
    }
    
    for (auto val : queue2) {
        sum2 += val;
        q2.push(val);
    }
    
    if ((sum1 + sum2) % 2 == 1) return -1;
    
    int return_condition = 4 * queue1.size();
    while (true) {
        if (answer == return_condition) {
            answer = -1;
            break;
        }
        
        int temp;
        if (sum1 < sum2) {
            temp = q2.front();
            q2.pop();
            sum2 -= temp;
            
            q1.push(temp);
            sum1 += temp;
        }
        
        else if (sum1 > sum2) {
            temp = q1.front();
            q1.pop();
            sum1 -= temp;
            
            q2.push(temp);
            sum2 += temp;
        }
        
        else break;
        
        answer++;
    }
    
    return answer;
}