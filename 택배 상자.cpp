#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector <int> sub_container;
    size_t length = order.size(), cnt=0;
    
    for (size_t i=1; i<=length; ++i) {
        if (order[cnt] < i) {
            if (!sub_container.empty() && sub_container.back() == order[cnt]) {
                answer++;
                sub_container.pop_back();
                cnt++;
                i--;
            }
            else {
                break;
            }
        }
        
        else if (order[cnt] > i) {
            while (i < order[cnt]) {
                sub_container.push_back(i);
                i++;
            }
            
            answer++;
            cnt++;
        }
        
        else {
            answer++;
            cnt++;
        }
    }
    
    while (!sub_container.empty()) {
        if (sub_container.back() == order[cnt++]) {
            sub_container.pop_back();
            answer++;
        }
        else break;
    }
    return answer;
}