#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i=left; i<=right; ++i) {
        long long row = i / n;
        long long col = i % n;
        answer.push_back(max(row, col) + 1);
    }
    
    return answer;
}