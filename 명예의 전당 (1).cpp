#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector <int> answer;
    
    priority_queue <int, vector<int>, greater<int>> pq;
    for (auto val : score) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        answer.push_back(pq.top());
    }
    
    
    return answer;
}