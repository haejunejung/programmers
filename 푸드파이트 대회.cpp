#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    const size_t length = food.size();
    size_t i,j,cnt;
    for (i=1; i<length; ++i) {
        cnt = food[i] / 2;
        for (j=0; j<cnt; ++j) {
            answer += to_string(i);
        }
    }
    
    string temp = answer;
    reverse(temp.begin(), temp.end());
    answer = answer + '0' + temp;
    return answer;
}